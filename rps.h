#include <string>

const std::string MOVES = "RPS";
namespace Games
{
        class Agent
        {
                public:
                        virtual char move() const = 0;
                        virtual ~Agent() = 0;
        };
        class RockAgent: public Agent
        {
                public:
                        char move() const;
                        ~RockAgent();
        };
        class PaperAgent: public Agent
        {
                public:
                        char move() const;
                        ~PaperAgent();

        };
        class ScissorsAgent: public Agent
        {
                public:
                        char move() const;
                        ~ScissorsAgent();
        };
        class RandomAgent: public Agent
        {
                public:
                        char move() const;
                        ~RandomAgent();
        };
        int eval(const char& move1, const char& move2);
        void run_tournament(const std::vector<Agent*> &players);
        std::ostream& operator<<(std::ostream& ostr, const std::vector<Agent*> &players);
        void test_cases();
};
