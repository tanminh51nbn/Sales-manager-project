#include<bits/stdc++.h>
using namespace std;

void BanHang_Display(){
    cout<<"                TRANG CHU               "<<endl;
    cout<<" ______________________________________ "<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|   1. Bat dau ca lam                  |"<<endl;
    cout<<"|   2. Admin                           |"<<endl;
    cout<<"|   3. Thoat                           |"<<endl;
    cout<<"|______________________________________|"<<endl;
    cout<<"\t => Nhap lua chon: ";
}
void BanHang_Display_2(){
    cout<<"                 ADMINS                 "<<endl;
    cout<<" ______________________________________ "<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|   Password:                          |"<<endl;
    cout<<"|______________________________________|"<<endl;
}
void BanHang_Display_1(){
    cout<<" ______________________________________ "<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|   1. Thanh Toan                      |"<<endl;
    cout<<"|   2. Tong ket ca va dang xuat        |"<<endl;
    cout<<"|______________________________________|"<<endl;
    cout<<"\t => Nhap lua chon: ";
}
void ThanhToan_Display(){
    gotoxy((short)32,(short)2); cout<<"THANH TOAN"<<endl;
    gotoxy((short)17,(short)3); cout<<" ______________________________________ "<<endl;
    gotoxy((short)17,(short)4); cout<<"|                                      |"<<endl;
    gotoxy((short)17,(short)5); cout<<"|   1. Them  (+)                       |"<<endl;
    gotoxy((short)17,(short)6); cout<<"|   2. Xoa   (-)                       |"<<endl;
    gotoxy((short)17,(short)7); cout<<"|   3. Tinh Tien                       |"<<endl;
    gotoxy((short)17,(short)8); cout<<"|   4. Thoat                           |"<<endl;
    gotoxy((short)17,(short)9); cout<<"|______________________________________|"<<endl;
    gotoxy((short)19,(short)10); cout<<"=> Nhap lua chon:  "<<endl;

}
void Bills_Display(){
    cout<<" _________________________________________________________________________ "<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|                                                                         |"<<endl;
    cout<<"|   ID         Ten san pham                      Gia           So luong   |"<<endl;
    cout<<"|                                                                         |"<<endl;
}          //1t         2t                              8t              4t          1t=setw(8)
void Admin_Display(){                                                       
    cout<<"                 ADMINS                 "<<endl;
    cout<<" ______________________________________ "<<endl;
    cout<<"|                                      |"<<endl;
    cout<<"|   1. Tao mat hang moi                |"<<endl;
    cout<<"|   2. Xoa mat hang hien co            |"<<endl;
    cout<<"|   3. Xem tong thu nhap               |"<<endl;
    cout<<"|______________________________________|"<<endl;
    cout<<"\t => Nhap lua chon: ";
}
void themhangmoi_Display(){
    cout<<"                       TAO SAN PHAM                       "<<endl;
    cout<<" ________________________________________________________ "<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"|   ID nhan dang nhanh:                                  |"<<endl;
    cout<<"|   Ten san pham:                                        |"<<endl;
    cout<<"|   Gia niem yet:                           (nghin VND)  |"<<endl;
    cout<<"|   So luong:                                            |"<<endl;
    cout<<"|________________________________________________________|"<<endl;
}