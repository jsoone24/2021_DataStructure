#pragma once
#include <random>
#include <ctime>
#include <iostream>
#include "CustomerQueue.h"

static std::mt19937 gen = std::mt19937((unsigned int)time(NULL));
static std::uniform_real_distribution<> dist(0, 1);        

class BankSimulator{
    private:
        int nSimulation;
        double probArrival;
        int tMaxService;
        int totalWaitTime;
        int nCustomers;
        int nServedCustomers;
        CustomerQueue que;
        bool IsNewCustomer(){return dist(gen) < probArrival;}
        int RandServiceTime(){return (int)(tMaxService*dist(gen))+1;}
        void InsertCustomer(int arrivalTime){
            Customer a(++nCustomers, arrivalTime, RandServiceTime());
            std::cout << "고객 " << a.id << "방문 (서비스 시간: " << a.tService << "분)\n";
            que.enqueue(a);
        }
    public:
        BankSimulator():nCustomers(0),totalWaitTime(0),nServedCustomers(0){}
        void readSimulationParameters(){
            std::cout << "시뮬레이션 할 최대 시간 (예:10) = "; 
            std::cin >> nSimulation;
            std::cout << "단위시간에 도착하는 고객 수 (예:0.5) = ";
            std::cin >> probArrival;
            std::cout << "한 고객에 대한 최대 서비스 시간 (예:5) = ";
            std::cin >> tMaxService;
            std::cout << "---------------------------------\n";
        }
        void run(){
            int    clock = 0;        
            int    serviceTime = -1;
            while(clock < nSimulation){
                clock++;
                std::cout << "현재시각: " << clock << "\n";
                if(IsNewCustomer()){InsertCustomer(clock);}
                if(serviceTime > 0){serviceTime--;}
                else{
                    if(que.isEmpty()){continue;}
                    Customer a = que.dequeue();        
                    nServedCustomers++;
                    totalWaitTime += clock-a.tArrival;
                    std::cout << "고객 " << a.id << " 서비스 시작 (대기시간: " << clock-a.tArrival << "분)\n";
                    serviceTime = a.tService-1;
                }
            } 
        }
        void printStat() {
            std::cout << "---------------------------------\n";
            std::cout << "서비스 받은 고객수 = " << nServedCustomers << "명\n";
            std::cout << "전체 대기 시간 = " << totalWaitTime << "분\n";
            std::cout << "서비스고객 평균대기시간 = " << (double)totalWaitTime/nServedCustomers << "분\n";
            std::cout << "현재 대기 고객 수 = " << nCustomers-nServedCustomers << "명\n";
        }
};