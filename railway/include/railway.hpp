#include <set>
#include <string>
#include <queue>
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
    enum EError{
        SEAT_BUSY
    };
    enum ETrainState{
        IN_TRIP,
        IN_QUEUE,
        ARRIVED,
        DEPARTURED
    };



    class RailwayStation;
    class ITrain{
        friend RailwayStation;
        
        protected:
        
        unsigned int wagons;
        unsigned int id;
        ETrainState state;
        std::time_t arriving_time;
        std::string train_name;
        public:
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
    
    class VirtualTrain: public ITrain{
        unsigned int time_for_road; 
        void tick();

        public:
        VirtualTrain(unsigned int wagons, unsigned int time_to_arrive);
        virtual void update_params() override;
    };
    
    class RailwayStation{
        int rail_num;
        std::queue <std::shared_ptr<ITrain>> train_queue;
        std::vector <std::shared_ptr<ITrain>> rails;
        std::map<unsigned int,std::shared_ptr<ITrain>> trains;
        static RailwayStation * station_instance;
        static std::atomic<unsigned int> id_counter;
        public:
        
        RailwayStation(const int &rail_num);
        
        void train_event(const unsigned int &train_id, const ETrainEvent & train_event);
        std::shared_ptr<ITrain> get_train_by_id(unsigned int id);
        int get_rail_num() const;
        int get_train_queue_size() const;
        std::vector<std::shared_ptr<ITrain>> get_all_trains() const;

        std::vector<std::shared_ptr<ITrain>> get_trains_on_rail() const;
        static RailwayStation * get_instance();
        void register_train(std::shared_ptr<ITrain> train);        
                
    };

    
    

}