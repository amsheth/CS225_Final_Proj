/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <list>
#include "schedule.h"
#include "utils.h"
#include <algorithm>

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */

V2D file_to_V2D(const std::string & filename){
    // Your code here!
    V2D xyz;
    std::string str;
    std::string x;
    std::vector<std::string> abc;
    char comma=44;
    char nl=10;
    str=file_to_string(filename);
    x=Trim(str);
    int w=SplitString(x,nl,abc);
    for (int i=0;i<w;i++){
        std::vector<std::string> efg;
        int l=SplitString(abc[i],comma,efg);
        for (int j = 0; j < l; j++)
        {
            efg[j]=Trim(efg[j]);
        }
        
        xyz.push_back(efg);
    }

    return xyz;

}

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(const V2D & cv, const V2D & student){
    // YOUR CODE HERE
    std::vector<std::vector<std::string>> d;
    std:: vector<std::string> tmp;
    for (unsigned i=0;i<cv.size();i++){
        bool y;
        std::string cn=cv[i][0];
        tmp.push_back(cn);
        for (unsigned j = 1; j < cv[i].size(); j++)
        {
            std::string stud=cv[i][j];
            [&]{
            for (unsigned k = 0; k < student.size(); k++)
            {
                if (stud==student[k][0]){
                    for (unsigned m=1;m<student[k].size();m++){
                        if (cn==student[k][m]){
                          y=true;  
                          return;
                        }
                    }
                }
            }
            y=false;
            return;}();
            if (y){
                tmp.push_back(stud);
            } 
                      
        }
        if (tmp.size()>1){
            d.push_back(tmp);
        }
        tmp.clear();
        
    }
    return d;
}

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */

std::vector<int> greedyColoring(int x,int V,std::vector<std::vector<unsigned>> adj,const std::vector<std::string> &timeslots)
{
    
  
    // Assign the first color to first vertex
    
    /*if (x>=V){
        result.resize(1);
        return result;
    }*/
    // no color is assigned to u
    std::vector<int> result (V,-1);
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    std::vector<bool> available(V,false);
    std::vector<bool> wrks(V);
    // Assign colors to remaining V-1 vertices
    for (int x=0;x<(int)timeslots.size();x++){
        for (int u = 1; u < V; u++)
        result[u] = -1;
        result[x]  = 0;
        for (int u = 0; u < V; u++)
        {    if (u==x){
            continue;
        }
            // Process all adjacent vertices and flag their colors
            // as unavailable
            std::vector<unsigned>::iterator i;
            for (int i = 0; i < (int)adj[u].size(); ++i){
                if (adj[u][i]==1)
                    if (result[i] != -1)
                        available[result[i]] = true;  
            }
            // Find the first available color
            int cr;
            for (cr = 0; cr < V; cr++){
                if (available[cr] == false)
                    break;
            }
            result[u] = cr; // Assign the found color
    
            // Reset the values back to false for the next iteration
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = false;
            
        }
        for (int u = 0; u < V; u++)
        std::cout << "Vertex " << u << " --->  Color "
             << result[u] << std::endl;
        if (!(result[result.size()-1] >= (int)timeslots.size())){
            return result;
        }
    }
    return result; 
    
    // print the result
}
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    std::vector<std::vector<unsigned>> mat;
    std::vector<std::string> brt;
    int len=courses.size();
    for (unsigned i = 0; i < courses.size(); i++){
        mat.push_back(std::vector<unsigned>(courses.size(), 0));
    }
    for (size_t i=0; i<courses.size();i++){
        std::cout << courses[i][0] << std::endl;
        brt.push_back(courses[i][0]);

    }
    for (unsigned i = 0; i < brt.size(); i++){
        for(unsigned j = i; j < brt.size(); j++){
            if (courses[j][0] == courses[i][0]){
                continue;
            }
            for (unsigned k = 1; k < courses[i].size(); k++){
                for(unsigned l = 1; l < courses[i].size(); l++){
                    if (courses[i][k] == courses[j][l]){
                        mat[i][j] = 1;
                        mat[j][i] = 1;
                    }
                }
            }
        }
    }
    std::vector<int> res;
    res=greedyColoring(0,len,mat,timeslots);
    V2D zyx;
    zyx=comp(res,timeslots,brt);
    return zyx;}
V2D comp(std::vector<int> colors,const std::vector<std::string> &timeslots,std::vector<std::string> brt){
    V2D final;
    if (colors[colors.size()-1] >= (int)timeslots.size()){
        final.push_back({"-1"});
        return final;
    } else {
        for (unsigned i = 0; i < timeslots.size(); i++){
            final.push_back({timeslots[i]});
        }
        for (unsigned j = 0; j < brt.size(); j++){
            final[colors[j]].push_back(brt[j]);
        }
    }
    return final;
}
