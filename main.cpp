    #include <bits/stdc++.h>
    #include <iostream>
    #include <filesystem>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include<windows.h>

    using namespace std;



    void createFolder()
    {
        string path, foldername;
        cout << "Enter directory path: ";
        cin.ignore();

        getline(cin, path);
        cout << "Enter folder name: ";
        getline(cin, foldername);
        path += "\\" + foldername;

        if (CreateDirectory(path.c_str(), NULL))
        {
         cout << "Folder created successfully.\n";

        }

        else
        {
         cout << "Folder creation failed.\n";

        }

    }

    void createFile()
    {

        string path, filename;
        cout << "Enter directory path: ";
        cin.ignore();

        getline(cin, path);
        cout << "Enter file name: ";
        getline(cin, filename);
        path += "\\" + filename;
        ofstream file(path);
        if (!file.is_open())
        {
            cerr << "Error: could not create file\n";
        }

        else
        {
            file << "This is a new file.\n";
            file.close();
        }

        cerr << "File Created successfully\n";
        cerr << "\n";

    }

    void rename_file()
    {

        string oldpath, newpath;
        cout << "Enter current path: ";
        cin.ignore();

        getline(cin, oldpath);
        cout << "Enter new path: ";
        getline(cin, newpath);

        if (rename(oldpath.c_str(), newpath.c_str()) == 0)
        {
           cout << "File/Folder renamed successfully.\n";
        }

       else
       {
        cout << "File/Folder rename failed.\n";
       }

    }

    void search_files()
    {

        string path, fname;
        cout << "Enter directory path: ";
        cin.ignore();

        getline(cin, path);
        cout << "Enter file name: ";
        getline(cin, fname);
        path = path+ "\\"+fname;
        WIN32_FIND_DATA data;
        HANDLE h = FindFirstFile(path.data(), &data);
        if (h != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (data.dwFileAttributes == FILE_ATTRIBUTE_NORMAL ||data.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE)
                {
                    if (fname == data.cFileName)
                    {
                        cout << "File found at: " << data.cFileName << endl;
                        return;
                    }
                }
            }

            while (FindNextFile(h, &data));
            FindClose(h);
        }
        cout << "File not found.\n";
    }


    void delete_folder()
    {

        string path,foldername;
        cout << "Enter directory path: ";
        cin.ignore();
        getline(cin, path);

        if (rmdir(path.data()) == 0)
        {
            cout << "Folder deleted successfully.\n";

        }

        else
        {
            cout << "Folder deletion failed.\n";
        }

    }

    void delete_file()
    {

        string path,fname;
        cout << "Enter directory path: ";
        cin.ignore();
        getline(cin, path);
        cout << "Enter file name: ";
        getline(cin, fname);
        path = path+ "\\"+fname;

        if (remove(path.c_str()) == 0)
        {
            cout << "File deleted successfully.\n";
        }

        else
        {
            cout << "File deletion failed.\n";
        }

    }


    STARTUPINFO si1;
    PROCESS_INFORMATION pi1;

    int sum ()
    {

        // Setting up the STARTUPINFO structure for process 1
        ZeroMemory(&si1, sizeof(si1));

        ZeroMemory(&pi1, sizeof(pi1));
        BOOL bCreateProcess = NULL;


        bCreateProcess= CreateProcess("sum.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1);


        // Creating process 1 to show the summation of two numbers
        if (bCreateProcess!=true)
        {
            cout << "Error creating process 1." << endl;
            return 1;
        }


        cout << "\nProcess Creation Successful" << endl;
        cout<<"Process1 ID:"<<pi1.dwProcessId<<endl;


        // Wait for process to complete
        WaitForSingleObject(pi1.hProcess, INFINITE);


        // Close process
        CloseHandle(pi1.hProcess);

        return 0;
    }


    STARTUPINFO si2;
    PROCESS_INFORMATION pi2;

    int sub ()
    {


        // Setting up the STARTUPINFO structure for process 2
        ZeroMemory(&si2, sizeof(si2));

        ZeroMemory(&pi2, sizeof(pi2));
        BOOL bCreateProcess = NULL;


        bCreateProcess= CreateProcess("sub.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2);




        // Creating process 2 to show the subtraction of two numbers
        if (bCreateProcess!=true)
        {
            cout << "Error creating process 2." << endl;
            return 1;
        }


        cout << "\nProcess Creation Successful" << endl;
        cout<<"Process2 ID:"<<pi2.dwProcessId<<endl;


        // Wait for process to complete
        WaitForSingleObject(pi2.hProcess, INFINITE);


        // Close process
        CloseHandle(pi2.hProcess);

        return 0;
    }


    STARTUPINFO si3;
    PROCESS_INFORMATION pi3;

    int multi ()
    {


        // Setting up the STARTUPINFO structure for process 3
        ZeroMemory(&si3, sizeof(si3));

        ZeroMemory(&pi3, sizeof(pi3));
        BOOL bCreateProcess = NULL;


        bCreateProcess= CreateProcess("multi.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si3, &pi3);




        // Creating process 3 to show the multiplication of to numbers
        if (bCreateProcess!=true)
        {
            cout << "Error creating process 3." << endl;
            return 1;
        }


        cout << "\nProcess Creation Successful" << endl;
        cout<<"Process3 ID:"<<pi3.dwProcessId<<endl;


        // Wait for process to complete
        WaitForSingleObject(pi3.hProcess, INFINITE);


        // Close process
        CloseHandle(pi3.hProcess);

        return 0;
    }


    STARTUPINFO si4;
    PROCESS_INFORMATION pi4;

    int div ()
    {


        // Setting up the STARTUPINFO structure for process 4
        ZeroMemory(&si4, sizeof(si4));

        ZeroMemory(&pi4, sizeof(pi4));
        BOOL bCreateProcess = NULL;


        bCreateProcess= CreateProcess("div.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si4, &pi4);




        // Creating process 4 to show the division of two numbers
        if (bCreateProcess!=true)
        {
            cout << "Error creating process 4." << endl;
            return 1;
        }


            cout << "\nProcess Creation Successful" << endl;
            cout<<"Process4 ID:"<<pi4.dwProcessId<<endl;


        // Wait for process to complete
        WaitForSingleObject(pi4.hProcess, INFINITE);


        // Close process
        CloseHandle(pi4.hProcess);

        return 0;
    }


    void show()
    {

        cout<<"\nCurrently Running Processes with Process IDs: "<<endl;

        if(pi1.dwProcessId!=0)
        {
           cout<<"\nProcess Name: Summation\nProcess ID:"<<pi1.dwProcessId<<"\nStatus: running"<<endl;
        }


       if(pi2.dwProcessId!=0)
       {
           cout<<"\nProcess Name: Subtraction\nProcess ID:"<<pi2.dwProcessId<<"\nStatus: running"<<endl;
       }

       if(pi3.dwProcessId!=0)
       {
           cout<<"\nProcess Name: Multiplication \nProcess ID:"<<pi3.dwProcessId<<"\nStatus: running"<<endl;
       }

       if(pi4.dwProcessId!=0)
       {
           cout<<"\nProcess Name: Division\nProcess ID:"<<pi4.dwProcessId<<"\nStatus: running"<<endl;
       }

    }


    void killprocess()
    {

        int processID;

        cout<<"enter PID"<<endl;
        cin>>  processID;

        // Open a handle to the process with PROCESS_TERMINATE access
        HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);

        // If the handle is valid, terminate the process
        if (hProcess != NULL && processID==pi1.dwProcessId)
        {
            TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            pi1.dwProcessId = 0;
            cout<<"Process Name: Summation \nStatus: Terminated"<<endl;
        }

        if (hProcess != NULL && processID==pi2.dwProcessId)
        {
            TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            pi2.dwProcessId = 0;
            cout<<"Process Name: Subtraction \nStatus: Terminated"<<endl;
        }

        if (hProcess != NULL && processID==pi3.dwProcessId)
        {
            TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            pi3.dwProcessId = 0;
            cout<<"Process Name: Multiplication \nStatus: Terminated"<<endl;
        }


        if (hProcess != NULL && processID==pi4.dwProcessId)
        {
            TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            pi4.dwProcessId = 0;
            cout<<"Process Name: Division \nStatus: Terminated"<<endl;
        }

    }

    int main ()
    {


        int c;
        while(true)
        {
           cout<<"\n";
           cout<<"\t\t\t\t\t\t\*****************WELCOME TO THE FILE MANAGEMENT AND PROCESS MANAGEMENT SYSTEM*****************"<<endl;
           cout<<"\n1. Create File"<<endl;
           cout<<"2. Rename File/Folder"<<endl;
           cout<<"3. Search File"<<endl;
           cout<<"4. Delete Folder"<<endl;
           cout<<"5. Delete File"<<endl;
           cout<<"6. Create Folder"<<endl;
           cout<<"\n";
           cout<<"7. Run Sum Process"<<endl;
           cout<<"8. Run Sub Process"<<endl;
           cout<<"9. Run Multiplication Process"<<endl;
           cout<<"10.Run Division Process"<<endl;
           cout<<"11.Show All the Running Processes"<<endl;
           cout<<"12.Kill Processes"<<endl;
           cout<<"0. Exit"<<endl;
           cout<<"\nEnter Your Choice:"<<endl;
           cin>>c;


           if (c==1)
            {
            createFile();
            }

            else if(c==2)
            {
            rename_file();
            }

            else if(c==3)
            {
            search_files();
            }

            else if(c==4)
            {
            delete_folder();
            }

            else if(c==5)
            {
            delete_file();
            }

            else if(c==6)
            {
            createFolder();
            }

            else if(c==7)
            {
            sum();
            }

            else if(c==8)
            {
            sub();
            }

            else if(c==9)
            {
            multi();
            }

            else if(c==10)
            {
            div();
            }

            else if(c==11)
            {
            show();
            }

            else if(c==12)
            {
            killprocess();
            }

            else if(c==0)
            {
            cout << "Program Terminated" << endl;
            exit(0);

            }

            }

            return 0;

            }



