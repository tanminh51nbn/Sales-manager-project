#include "dropcoil.cpp"
#include "GiaoDien.cpp"
using namespace std;

fstream file;

class hangtonkho{
    private:
    string ten,id;
    int gia;

    protected:
    int sl;
    public:
    hangtonkho(){}
    hangtonkho(string ten, string id, int gia, int sl){
        this->ten=ten;
        this->id=id;
        this->gia=gia;
        this->sl=sl;
    }
    string get_ten(){
        return ten;
    }
    string get_id(){
        return id;
    }
    int get_gia(){
        return gia;
    }
    int get_soluong(){
        return sl;
    }
    void set_gia(int gia){
        this->gia=gia;
    }
    void set_ten(string ten){
        this->ten=ten;
    }
    void set_id(string id){
        this->id=id;
    }
    void set_sl(int sl){
        this->sl=sl;
    }
    void ban(int x){
        sl-=x;
    }
};

//ham nhap de tao mat hang moi.
void nhap_hangmoi(string &ten, string &id, int &gia, int &sl){
    system("cls");
    themhangmoi_Display();
    gotoxy((short)16,(short)3); cin>>id;
    gotoxy((short)18,(short)4); cin.ignore(); getline(cin,ten);
    gotoxy((short)18,(short)5); cin>>gia;
    gotoxy((short)14,(short)6); cin>>sl;
}
bool check(string id){
    string s;
    bool k;
    file.open("hanghoa.txt", ios::in);
    while (getline(file,s)){
        if(s==id){
            return true;
            break;
        } else return false;
    }
}
//ham check id, xem id da ton tai chua. Chua thi them mat hang moi.
void check_and_save(string ten, string id, int gia, int sl){
    if(check(id)==false){
        //luu vao file khi da dat tieu chuan
        file.close();
        file.open("hanghoa.txt", ios::app);
        file<<id<<endl;
        file<<ten<<endl;
        file<<gia<<endl;
        file<<sl<<endl;
        cout<<endl<<"Tao thanh cong !!!!!"<<endl;
        system("pause");
        file.close();
    }else{
        cout<<endl<<"=> Da ton tai mat hang co ID la: \""<<id<<"\""<<endl;
        system("pause");
    }
}
//doc file hanghoa.txt de so huu du lieu cho qua trinh xu li!
void khoitao_dulieu(vector<hangtonkho> &mu){
    string s;
    hangtonkho a;
    file.open("hanghoa.txt", ios::in);
    short k=0;
    while(getline(file,s)){
        switch(k){
            case 0:
            a.set_id(s);
            break;

            case 1:
            a.set_ten(s);
            break;
            
            case 2:
            a.set_gia(atoi(s.c_str()));
            break;

            case 3:
            a.set_sl(atoi(s.c_str()));
            mu.push_back(a);
            break;
        }
        k++;
        if(k==4) k=0;
    }
    file.close();
}
void retype(vector<hangtonkho> &a){
    remove("hanghoa.txt");
    file.open("hanghoa.txt", ios::out);
    for(int line=0; line<a.size(); line++){
        file<<a[line].get_id()<<endl;
        file<<a[line].get_ten()<<endl;
        file<<a[line].get_gia()<<endl;
        file<<a[line].get_soluong()<<endl;
    }
    file.close();
}
bool set_password(int password){
        int true_password=((16118121&2351)<<5);
        if(password==true_password) return true;
        else return false;
}
//ham xoa du lieu trong vector
void xuat_Admin(vector<hangtonkho> a){
    system("cls");
        cout<<left<<setw(14)<<"ID"<<setw(62)<<"| Ten san Pham"<<setw(15)<<"| Gia (VND)"<<"| So luong"<<endl;
        cout<<"--------------|-------------------------------------------------------------|--------------|---------------"<<endl;
    for(int line=0;line<a.size();line++){
        cout<<left<<setw(14)<<a[line].get_id()<<"| "<<setw(60)<<a[line].get_ten()<<setw(15)<<"| "+edit(a[line].get_gia())+",000"<<"| "<<a[line].get_soluong()<<endl;
    }
}
void xoas(vector<hangtonkho> &a){
    xuat_Admin(a);
    string del_id;
    cout<<endl<<"=> Nhap ID san pham muon xoa: "; cin>>del_id;
    bool k;
    for(int line=0;line<a.size();line++){
        if(a[line].get_id()==del_id){
            for(int j=line;j<a.size();j++){
                for(int l=j+1;l<a.size();l++){
                    a[j]=a[l];
                    break;
                }
            }
            a.pop_back();
            k=true;
            break;
        } else k=false;
    }
    
    if(k==false){
        cout<<"Khong tim thay san pham co ID la: \""<<del_id<<"\""<<endl;
        system("pause");
    }
    xuat_Admin(a);
    system("pause");
}
//thanh toan va tao bill
void sells_n_bills(vector<hangtonkho> &a,vector<int> &b,vector<int> &c){
    struct form
    {
        string id;
        int sl,gia;
    };
    
    int n,sl;
    string id;
    form x;
    vector<form> messi;
    short line=13;
    system("cls");
    Bills_Display();
    do{
        ThanhToan_Display();
        gotoxy((short)0,(short)line+1);cout<<"|_________________________________________________________________________|";
        gotoxy((short)37,(short)10);cin>>n;
        switch(n){
            case 1: //them
                gotoxy((short)0,(short)line);cout<<left<<setw(74)<<"|"<<"|";
                gotoxy((short)4,(short)line); cin>>id;
                for(int i=0;i<a.size();i++){
                    if(a[i].get_id()==id){
                        gotoxy((short)4,(short)line);cout<<a[i].get_id();
                        gotoxy((short)15,(short)line);
                        if(a[i].get_ten().length()>30){
                            string virtual_str=a[i].get_ten();
                            virtual_str.resize(28);
                            cout<<virtual_str+"...";
                        }else{
                            cout<<a[i].get_ten();
                        }
                        gotoxy((short)49,(short)line);cout<<edit(a[i].get_gia())<<",000";
                        gotoxy((short)63,(short)line); cin>>sl;
                        if(sl>a[i].get_soluong()){
                        gotoxy((short)63,(short)line);cout<<"Het Hang \n\n\n"; system("pause");
                        gotoxy((short)4,(short)line); cout<<"                                                                     ";
                        }else{
                            x.id=id;
                            x.sl=sl;
                            x.gia=a[i].get_gia();
                            messi.push_back(x);
                            line++;
                            gotoxy((short)0,(short)line); cout<<"|                                                                         |";
                        }
                        break;
                    }else{
                        gotoxy((short)4,(short)line); cout<<"                                                                     ";
                    }
                }
                n=0;
            break;
            
            case 2: //xoa
                if(line>13){
                    gotoxy((short)0,(short)line+1); cout<<"                                                                         ";
                    gotoxy((short)0,(short)line);cout<<"|_________________________________________________________________________|";
                    gotoxy((short)0,(short)line-1); cout<<"|                                                                         |";
                    line--;
                }
                n=0;
            break;

            case 3: //tinh tien
                if(line>13){
                    for(int i=0;i<messi.size();i++){
                        for(int j=0;j<a.size();j++){
                            if(messi[i].id==a[j].get_id()){
                                a[i].ban(messi[i].sl);
                                break;
                            }
                        }
                    }
                    int tongtien=0;
                    file.open("lichsugiaodich.txt",ios::app);
                    for(int i=0;i<messi.size();i++){
                        file<<left<<setw(16)<<messi[i].id<<setw(16)<<messi[i].gia<<setw(16)<<messi[i].sl<<messi[i].gia*messi[i].sl<<endl;
                        tongtien+=messi[i].gia*messi[i].sl;
                    }
                    file.close();
                    gotoxy((short)0,(short)line+1);cout<<"|                                                                         |";
                    gotoxy((short)10,(short)line+1);cout<<"Tong Tien: "<<edit(tongtien)<<",000 VND";
                    gotoxy((short)0,(short)line+2);cout<<"|_________________________________________________________________________|";
                    cout<<endl<<endl;
                    system("pause");
                    retype(a);
                    file.open("TongThuNhap.txt",ios::app);
                    file<<tongtien<<endl;
                    file.close();
                    c.push_back(tongtien);
                }
                messi.clear();
            break;
        }
        if(n==4 or n==3){
            line=13;
            break;
        }
    } while (true);
}

int main(){
    string ten, id, time, s;
    int gia, sl, password;
    short n=1;
    vector<hangtonkho> get_data;
    vector<int> tongthunhap;
    vector<int> tongca;
    
    while(true){
        khoitao_dulieu(get_data);
        system("cls");
        BanHang_Display();
        cin>>n;
        switch(n){
            case 1:
                    time=time_in_life();
                    file.open("lichsugiaodich.txt",ios::app);
                    file<<time_in_life()<<endl;
                    file.close();
                do{
                    system("cls");
                    BanHang_Display_1();
                    cin>>n;
                    switch(n){
                        case 1:
                            sells_n_bills(get_data,tongthunhap,tongca);
                        break;

                        case 2:
                            system("cls");
                            cout<<left<<setw(16)<<"ID"<<setw(16)<<"Gia"<<setw(16)<<"So luong"<<"Tong tien"<<endl;
                            file.open("lichsugiaodich.txt",ios::in);
                            while(getline(file,s)){
                                if(s==time){
                                    do{
                                        cout<<s<<endl;
                                    }while(getline(file,s));
                                    break;
                                }
                            }
                            file.close();
                            cout<<" => Tong tien ca: "<<xuli_vetor(tongca)<<",000 VND"<<endl<<endl;
                            system("pause");
                            tongca.clear();
                        break;
                    }
                    if(n==2){
                        break;
                    }
                }while(true);
                n=0;
            break;

            case 2:
                system("cls");
                BanHang_Display_2();
                gotoxy((short)14,(short)3); cin>>password;
                while(true){
                    if(set_password(password)==true){
                        system("cls");
                        Admin_Display();
                        cin>>n;
                        switch(n){
                            case 1:
                                nhap_hangmoi(ten,id,gia,sl);
                                check_and_save(ten,id,gia,sl);
                            break;

                            case 2:
                                xoas(get_data);
                                retype(get_data);
                            break;

                            case 3:{
                                string s;
                                file.open("lichsugiaodich.txt",ios::in);
                                while(getline(file,s)){
                                    cout<<s<<endl;
                                }
                                file.close();

                                int x=0;
                                file.open("TongThuNhap.txt",ios::in);
                                while(file>>s){
                                    x+=atoi(s.c_str());
                                }
                                file.close();
                                cout<<endl<<"Tong thu nhap: "<<edit(x)<<",000 VND"<<endl<<endl;
                                system("pause");

                                tongthunhap.clear();
                            }
                            break;
                        }
                    }
                    if(n==4){
                        break;
                    }
                }
            break;
        }
        if(n==3){
            get_data.clear();
            break;
        }
    }
    return 0;
}