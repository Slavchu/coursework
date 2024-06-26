#include <set>
#include <string>
#include <deque>
#include <vector>
#include <memory>
#include <ctime>
#include <map>
#include <atomic>
namespace railway{


    
    enum ETrainEvent{
        TRAIN_LATE,
        TRAIN_ARRIVED,
        TRAIN_DEPARTURING
    };

    enum ETrainState{
        IN_TRIP,
        IN_QUEUE,
        ARRIVED,
        DEPARTURED,
        IN_TRIP_LATE
    };



    class RailwayStation;
    class ITrain{
        friend RailwayStation;
        
        protected:
        
        unsigned int wagons;
        unsigned int id;
        unsigned int lateness = 0;
        ETrainState state;
        std::time_t arriving_time;
        std::string train_name;
        public:
        unsigned int get_lateness () const;
        unsigned int get_id() const;
        unsigned int get_wagons () const;
        std::time_t get_arriving_time() const;
        std::string get_arriving_time_string() const;
        std::string get_train_name() const;
        void set_train_name(const std::string &name);
        ETrainState get_state() const;
        
        ITrain();
        virtual void update_params() = 0;
    };
    
    class VirtualTrain final: public ITrain{
        std::atomic<unsigned short> delayed_times = 0;
        std::atomic<unsigned short> time_for_road = 0; 
        std::atomic<unsigned short> time_to_stay = 0;
        void tick();
        
        public:
        VirtualTrain(unsigned int wagons, unsigned int time_to_arrive, unsigned time_to_stay= 5);
        virtual void update_params() override;
    };
    
    class RailwayStation final{
        int rail_num;
        std::deque <std::shared_ptr<ITrain>> train_queue;
        std::vector <std::shared_ptr<ITrain>> rails;
        std::map<unsigned int,std::shared_ptr<ITrain>> trains;
        static RailwayStation * class_instance;
        static std::atomic<unsigned int> id_counter;
        
       
        public:
        
        RailwayStation(const int &rail_num);
        
        void train_event(const unsigned int &train_id, const ETrainEvent & train_event);
        std::shared_ptr<ITrain> get_train_by_id(const unsigned int &train_id);
        int get_rail_num() const;
        int get_train_queue_size() const;
        std::vector<std::shared_ptr<ITrain>> get_all_trains() const;
        std::vector<std::shared_ptr<ITrain>> get_trains_in_queue() const ;
        std::vector<std::shared_ptr<ITrain>> get_trains_on_rail() const;
        static RailwayStation * get_instance();
        void register_train(std::shared_ptr<ITrain> train);        
                
    };
    class RailwayStationStat final{
        static RailwayStationStat * class_instance;
        RailwayStationStat() {};
        
        unsigned int average_delay;
        public:
        
        unsigned int get_average_delay() ; 
        static RailwayStationStat * get_instance();
    };
    
    

}