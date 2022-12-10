/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

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
    V2D *retvec = new V2D;
    std::string file = file_to_string(filename);
    file = Trim(file);
    int i = 0;
    std::vector<std::string> fields;
    int numlines = SplitString(file, '\n', fields);
    while(i < numlines)    {
        std::vector<std::string> line;
        int useless = SplitString(fields[i], ',', line);
        int temp = 1;
        temp = useless;
        useless = temp;           // removes compiler warning
        (*retvec).push_back(line);
        i++;
    }

    // remove whitespace using trim

    for(unsigned k = 0; k < (*retvec).size(); k++)   {
        for(unsigned m = 0; m < (*retvec)[k].size(); m++)    {
            (*retvec)[k][m] = Trim((*retvec)[k][m]);
        }
    }
    return *retvec;
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

    std::vector<std::vector<bool>> should_add1(cv.size(), std::vector<bool>(cv.size(), false));          // vector of bool flags determining what to add in the returned V2D
    std::vector<std::vector<bool>> should_add2(cv.size(), std::vector<bool>(cv.size(), false));          // vector of bool flags determining what to add in the returned V2D


    // because of the way this program works, should_add1 needs to have its first column all set to true.
    // otherwise, the program will not add any of the course names.

    for(unsigned i = 0; i < should_add2.size(); i++)    {
        should_add1[i][0] = true;
    }   

    // first vector checks which students exist in the cv.
    // second vector checks which classes the student takes in the student file.

    // first, check what classes have which students, using the cv V2D.
    // since the bools default to false, missing students will automatically be marked as false.

    for(unsigned i = 0; i < cv.size(); i++) {
        for(unsigned j = 1; j < cv[i].size(); j++)  {
            for(unsigned k = 0; k < student.size(); k++)    {
                if(cv[i][j] == student[k][0])   {
                    should_add1[i][j] = true;
                    continue;
                }
            }
        }
    }       

    // we are done modifying should_add1, now we need to check if the student file matches up.
    // should_add2 will check what classes the students are registered for on their file.

    for(unsigned i = 0; i < student.size(); i++) {
        for(unsigned j = 1; j < student[i].size(); j++)  {
            for(unsigned k = 0; k < cv.size(); k++)    {
                if(student[i][j] == cv[k][0])   {

                    for(unsigned l = 0; l < cv.size(); l++) {
                        if(cv[l][0] == student[i][j])   {
                            for(unsigned m = 1; m < cv[l].size(); m++)  {
                                if(cv[l][m] == student[i][0])   {
                                    should_add2[l][m] = true;
                                    should_add2[l][0] = true;
                                }
                            }
                        }
                    }

                }
            }
        }
    }       

    V2D retvec;
    for(unsigned i = 0; i < should_add1.size(); i++) {
        std::vector<std::string> line;
        for(unsigned j = 0; j < should_add1.size(); j++)  {
            if(should_add1[i][j] && should_add2[i][j])  {
                line.push_back(cv[i][j]);
            }
        }
        if(!line.empty())   {
            retvec.push_back(line);
        }
    }       
    return retvec;
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
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    // Your code here!
    V2D retvec;


    
    std::vector<std::string> line;
    line.push_back("-1");
    retvec.push_back(line);
    

    
    return retvec;
}