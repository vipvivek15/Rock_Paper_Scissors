#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <iterator>
#include "rps.h"
using namespace Games;
namespace Games
{
        Agent::~Agent() { if(this!=nullptr) delete this;  }
        char RockAgent::move() const{ return 'R'; }
        RockAgent::~RockAgent() { if(this!=nullptr) delete this;  }
        char PaperAgent::move() const{ return 'P'; }
        PaperAgent::~PaperAgent() { if(this!=nullptr) delete this; }
        char ScissorsAgent::move() const { return 'S'; }
        ScissorsAgent::~ScissorsAgent() { if(this!=nullptr) delete this;  }
        char RandomAgent::move() const
        {
                srand(time(0));
                return MOVES[rand()%(MOVES.length())];
        }
        RandomAgent::~RandomAgent() { if(this!=nullptr) delete this; }
        int eval(const char& move1, const char& move2)
        {
                if(move1 == move2) return 0;
                else if(MOVES.find(move1) == (MOVES.find(move2)+1)%3) return 1;
                else if(MOVES.find(move2) == (MOVES.find(move1)+1)%3) return 2;
                else return -1;
        }
         void run_tournament(const std::vector<Agent*> &players)
        {
                std::unordered_map<Agent*,int> wins;
                std::unordered_map<Agent*,int> losses;
                std::unordered_map<Agent*,int> draws;
                int winner;
                for(const auto& p1: players)
                {
                        for(const auto& p2: players)
                        {
                                if(p1==p2) continue;
                                winner = eval(p1->move(),p2->move());
                                if(winner == 0)
                                {
                                        draws[p1]+=1;
                                        draws[p2]+=1;
                                }
                                else if(winner == 1)
                                {
                                        wins[p1]+=1;
                                        losses[p2]+=1;
                                }
                                else if(winner == 2)
                                {
                                        losses[p1]+=1;
                                        wins[p2]+=1;
                                }
                        }
                }
                /*indicate the number of wins, losses and draws for all the players*/
                for(std::unordered_map<Agent*,int>::iterator it = wins.begin();it!=wins.end();it++)
                        std::cout << "Player " << typeid(*it->first).name() << " has won: " << it->second << " number of times " << std::endl;
                for(std::unordered_map<Agent*,int>::iterator it = draws.begin();it!=draws.end();it++)
                        std::cout << "Players " << typeid(*it->first).name() << " have drawn: " << it->second << " number of times " << std::endl;
                for(std::unordered_map<Agent*,int>::iterator it = losses.begin();it!=losses.end();it++)
                        std::cout << "Player " << typeid(*it->first).name() << " has lost: " << it->second << " number of times " << std::endl;
        }
        std::ostream& operator<<(std::ostream& ostr, const std::vector<Agent*> &players)
        {
                for(const auto& player: players)
                        ostr << "Player " << typeid(*player).name() << " move is: " << player->move() << std::endl;
                return ostr;
        }
        void display()
        {
                int option;
                std::vector<Agent*> agent;
                while(1)
                {
                        std::cout << std::endl;
                        std::cout << "Enter agents you would like to play rock, paper and scissors: " << std::endl;
                        std::cout << "Options: " << std::endl;
                        std::cout << "1: Rock, Paper, Scissors, Random" << std::endl;
                        std::cout << "2: Rock, Paper, Scissors" << std::endl;
                        std::cout << "3: Rock, Random, Paper" << std::endl;
                        std::cout << "4: Rock, Random, Scissors" << std::endl;
                        std::cout << "5: Paper, Random, Rock" << std::endl;
                        std::cout << "6: Paper, Random, Scissors" << std::endl;
                        std::cout << "7: Scissors, Random, Paper" << std::endl;
                        std::cout << "8: Scissors, Random, Rock" << std::endl;
                        std::cout << "9: Custom" << std::endl;
                        std::cout << "10: Run Random Once" << std::endl;
                        std::cout << "11: Run Random Arbitrary Number Of Times" << std::endl;
                        std::cout << "12: Exit" << std::endl;
                        std::cin >> option;
                        switch(option)
                        {
                                case 1:
                                {
                                        agent = {new RockAgent, new PaperAgent, new ScissorsAgent, new RandomAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 2:
                                {
                                        agent = {new RockAgent, new PaperAgent, new ScissorsAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 3:
                                {
                                        agent = {new RockAgent, new RandomAgent, new PaperAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 4:
                                {
                                        agent = {new RockAgent, new RandomAgent, new ScissorsAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 5:
                                {
                                        agent = {new PaperAgent, new RandomAgent, new RockAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 6:
                                {
                                        agent = {new PaperAgent, new RandomAgent, new ScissorsAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 7:
                                {
                                        agent = {new ScissorsAgent, new RandomAgent, new PaperAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 8:
                                {
                                        agent = {new ScissorsAgent, new RandomAgent, new RockAgent};
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 9:
                                {
                                        unsigned AGENT_NUMBER;
                                        char option;
                                        std::cout << "Enter number of agents you would like to play" << std::endl;
                                        std::cin >> AGENT_NUMBER;
                                        while(AGENT_NUMBER < 1)
                                        {
                                                std::cout << "Enter a valid size greater than 1" << std::endl;
                                                std::cin >> AGENT_NUMBER;
                                        }
                                        for(unsigned i = 0; i < AGENT_NUMBER; i++)
                                        {
                                                std::cout << "Enter agent move you would like to enter: " << std::endl;
                                                std::cout << "R: rock" << std::endl;
                                                std::cout << "P: paper" << std::endl;
                                                std::cout << "S: scissors" << std::endl;
                                                std::cout << "D: random" << std::endl;
                                                std::cin >> option;
                                                while(option != 'R' && option != 'P' && option!= 'S' && option!='D' && option!= 'r' && option!='p' && option!='s' && option !='d')
                                                {
                                                        std::cout << "Please enter valid option of R, P, S or D only. Thank you. " << std::endl;
                                                        std::cin >> option;
                                                }
                                                std::cout << "Entering choice " << i+1 << " now" << std::endl;
                                                std::cout << "You have entered choice: " << option << std::endl;
                                                if(option == 'R' || option == 'r')
                                                {
                                                        std::cout << "You have chosen rock agent." << std::endl;
                                                        agent.emplace_back(new RockAgent);
                                                }
                                                else if(option == 'P' || option == 'p')
                                                {
                                                        std::cout << "You have chosen paper agent." << std::endl;
                                                        agent.emplace_back(new PaperAgent);
                                                }
                                                else if(option == 'S' || option == 's')
                                                {
                                                        std::cout << "You have chosen scissors agent. " << std::endl;
                                                        agent.emplace_back(new ScissorsAgent);
                                                }
                                                else if(option == 'D' || option == 'd')
                                                {
                                                        std::cout << "You have chosen random agent. " << std::endl;
                                                        srand(time(0));
                                                        agent.emplace_back(new RandomAgent);
                                                }
                                        }
                                        std::cout << "Stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                 case 10:
                                {
                                        std::cout << std::endl;
                                        std::cout << "Now arbitrary number of agent of max size 10 playing with arbitrary moves" << std::endl;
                                        srand(time(0));
                                        static const unsigned CAPACITY = 10;
                                        unsigned SIZE = rand()%CAPACITY+1;
                                        char option;
                                        for(unsigned i = 0; i < SIZE; i++)
                                        {
                                                option = MOVES[rand()%(MOVES.length())];
                                                std::cout << "Choice is: " << i+1 << std::endl;
                                                switch(option)
                                                {
                                                        case 'R':
                                                                std::cout << "Rock agent randomly chosen" << std::endl;
                                                                agent.emplace_back(new RockAgent);
                                                                break;
                                                        case 'P':
                                                                std::cout << "Paper agent randomly chosen" << std::endl;
                                                                agent.emplace_back(new PaperAgent);
                                                                break;
                                                        case 'S':
                                                                std::cout << "Scissors agent randomly chosen" << std::endl;
                                                                agent.emplace_back(new ScissorsAgent);
                                                                break;
                                                        default:
                                                                std::cout << "Valid option not found" << std::endl;
                                                                break;
                                                }
                                        }
                                        std::cout << "Random stats: " << std::endl;
                                        run_tournament(agent);
                                        std::cout << agent;
                                        agent.clear();
                                        break;
                                }
                                case 11:
                                {
                                        std::cout << std::endl;
                                        std::cout << "Now arbitrary number of agent of max size 10 playing with arbitrary moves" << std::endl;
                                        unsigned USER_SIZE;
                                        std::cout << "Enter the number of times you would like to play randomly less than 10: " << std::endl;
                                        std::cin >> USER_SIZE;
                                        srand(time(0));
                                        static const unsigned CAPACITY = 10;
                                        char option;
                                        for(unsigned j =0; j < USER_SIZE; j++)
                                        {
                                                std::cout << std::endl;
                                                std::cout << "Running tournament: " << j+1 << std::endl;
                                                for(unsigned i = 0; i < rand()%CAPACITY+1; i++)
                                                {
                                                        std::cout << std::endl;
                                                        option = MOVES[rand()%(MOVES.length())];
                                                        std::cout << "Choice is: " << i+1 << std::endl;
                                                        switch(option)
                                                        {
                                                                case 'R':
                                                                        std::cout << "Rock agent randomly chosen" << std::endl;
                                                                        agent.emplace_back(new RockAgent);
                                                                        break;
                                                                case 'P':
                                                                        std::cout << "Paper agent randomly chosen" << std::endl;
                                                                        agent.emplace_back(new PaperAgent);
                                                                        break;
                                                                case 'S':
                                                                        std::cout << "Scissors agent randomly chosen" << std::endl;
                                                                        agent.emplace_back(new ScissorsAgent);
                                                                        break;
                                                                default:
                                                                        std::cout << "Valid option not found" << std::endl;
                                                                        break;
                                                        }
                                                }
                                                std::cout << std::endl;
                                                std::cout << "Random stats for tournament: " << j+1 << std::endl;
                                                std::cout << std::endl;
                                                run_tournament(agent);
                                                std::cout << agent;
                                                agent.clear();
                                        }
                                        break;
                                }
                                case 12:
                                {
                                        std::string _name;
                                        std::cout << "Enter your name: " << std::endl;
                                        std::cin >> _name;
                                        std::cout << "Hope you enjoyed playing rock paper scissors. Hope you play again " << _name << "." << std::endl;
                                        return;
                                }
                                default:
                                {
                                        std::cout << "Please enter a valid option from 1 to 10, thank you" << std::endl;
                                        break;
                                }
                        }
                }
        }
}
int main()
{
        display();
        return 0;
}



