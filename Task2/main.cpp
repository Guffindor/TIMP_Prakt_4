#include <AES.h>
#include <GOST.h>

int main ()
{
    unsigned op, alg;
    string file_in, file_out, key;
    while(true){
        cout << "Выберите одну из опций (0-выход, 1-AES, 2-ГОСТ): ";
        cin >> alg;
        if (alg == 0) break;
            
            
        
			if (alg > 0 && alg < 3) {
            cout << "Введите путь к файлу с исходными данными: ";
            cin >> file_in;
            cout << "Введите путь результирующего файла: ";
            cin >> file_out;
            cout << "Введите ключ: ";
            cin >> key;
            if (alg == 1) {
                modAES aes(file_in, file_out, key);
				cout << "Что хотите сделать?? (1 - зашифровать, 2 - расшифровать)" << endl;
				cin >> op;
                if (op == 1) {
                    if (aes.encrypt())
                        cout << "Зашифрование выполнено" << endl;
                    else
                        cout << "Зашифрование отклонено " << endl;
                } else {
                    if (aes.decrypt())
                        cout << "Расшифрование выполнено" << endl;
                    else
                        cout << "Расшифрование отклонено" << endl;
                }
            }
            else if (alg == 2) {
                modGOST gost(file_in, file_out, key);
				cout << "Что хотите сделать?? (1 - зашифровать, 2 - расшифровать)" << endl;
				cin >> op;
                if (op == 1) {
                    if (gost.encrypt())
                        cout << "Зашифрование выполнено" << endl;
                    else
                        cout << "Зашифрование отклонено" << endl;
                } else {
                    if (gost.decrypt())
                        cout << "Расшифрование выполнено" << endl;
                    else
                        cout << "Расшифрование отклонено" << endl;
                }
            }
            else {
                cerr << "Неправильный формат данных" << endl;
            }
        }
    }
    return 0;
}
