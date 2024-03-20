#include <set>
#include <string>
#include <queue>
#include <vector>
#include <memory>
namespace types{
    struct Date{
        unsigned int d, m, y, h, s;
        bool operator < (Date& other){
            if(y < other.y)
                return true;
            if(m < other.m)
                return true;
            if(d < other.d)
                return true;
            if(h < other.h)
                return true;
            if (s < other.s)
                return true;
            return false;
        }
};
}
namespace railway{


    
    enum ETrainEvent{
        TRAIN_LATE,
        TRAIN_IN_QUEUE,
        TRAIN_ARRIVED,
        TRAIN_DEPARTURING
    };
    enum EError{
        SEAT_BUSY
    };
    enum ETrainState{
        IN_TRIP,
        ARRIVED,
        DEPARTURED
    };



    class RailwayStation;
    class ITrain{
        friend RailwayStation;
        
        unsigned int wagons;
        unsigned int id;
        ETrainState state;
        types::Date arriving_date;
        std::string train_name;
        public:
        ITrain();
        virtual void depart() = 0;
        virtual void update_params() = 0;
    };
    
    class VirtualTrain: public ITrain{
        
        public:
        VirtualTrain();
        virtual void update_params() override;
        virtual void depart () override;
    };
    
    class RailwayStation{
        int rail_num;
        std::queue <std::shared_ptr<ITrain>> train_queue;
        std::vector <std::shared_ptr<ITrain>> rails;
        static RailwayStation * station_instance;
        
        public:
        
        RailwayStation(const int &rail_num);
        void train_event(ITrain &train, const ETrainEvent & train_event);
        int get_rail_num() const;
        int get_train_queue_size() const;
        std::vector<std::shared_ptr<const ITrain>> get_trains_on_rail() const;
        static RailwayStation * get_instance();

        
                
    };

    
    

}