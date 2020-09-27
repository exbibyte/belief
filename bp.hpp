#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <vector>
#include <set>
#include <initializer_list>

class N {
    
private:
    
    int label; //selected label after optimization
    int count_labels; //current node labels
    std::vector<std::unordered_map<N*,double>> msg_label; //holds incoming messages, label -> neighbour -> message
    std::vector<std::unordered_map<N*,double>> msg_label_swap;
    std::vector<N*> neighbour;
    std::vector<double> belief;
    
public:

    int get_label() const;
    
    void set_labels(int count_labels);

    void set_neighbour(N* const n);
    
    static void cycle(std::vector<N*> & nodes,
		      std::function<double(N* const, int const)> f_node,
		      std::function<double(N* const, int const, N* const, int const)> f_edge);
    
    void update_belief(std::function<double(N* const, int const)> f_node,
		       std::function<double(N* const, int const, N* const, int const)> f_edge);
    
    void distribute_msg(std::function<double(N* const, int const)> f_node,
			std::function<double(N* const, int const, N* const, int const)> f_edge);
    
    void update_msg();

    void debug_label();
};
