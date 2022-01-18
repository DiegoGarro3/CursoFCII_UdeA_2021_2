#include<iostream>
#include<string>


using namespace std;

int main()
{
    //List with students and their grade
    string lista[10]={"Juan 1", "Andres 1", "Pedro 1", 
                    "Maria 1", "Sara 1", "Daniela 1", 
                    "Luis 2", "Pamela 1", "Camilo 1",
                    "Carolina 1"};

    
    unsigned int c = 0;

    for(int i=0; i < 10;i++) 
    {
        string entry = lista[i];
        char value = entry[entry.length() - 1];//Extract the number of the string
        
        switch(value)
        {   case '1':
                c++; //Add 1 to c if grade is 1
                break;
            
            case '2':
                break; //Do nothing if grade is 12
            
            default:
                cout<<"¡¡¡Revise las calificaciones de <"<< lista[i] << "> no son adecuadas!!!" <<endl; 
                break;
        }
    }


    if(c > 8)
    {   
        //Print a message if more than 8 students approve
        cout << "Aprobaron "<< c << " alumnos, "<< "Excelente instructor." <<  endl;
    }


    else if(6 < c &  c<=8)
    {   
        //Print a message if more between 7 or 8 students approve
        cout << "Aprobaron "<< c << " alumnos, "<< "Buen instructor." <<  endl;
    }
    
    else

        //Print a message if less than 7 students approve
        cout << "Aprobaron "<< c << " alumnos, "<< "El instructor debe mejorar." <<  endl;

    return 0;  
}