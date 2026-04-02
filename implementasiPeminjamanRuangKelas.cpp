#include <iostream>
using namespace std;

// Deklarasi data yang akan disimpan
struct Data {
    string nama;
    int NIU;
    string jam;
    int durasi;
    string alasan;
    string ruangan;  
};

// Node untuk stack
struct NodeStack {
    Data values;
    int status;
    NodeStack* next;
};

// Node untuk queue
struct NodeQueue {
    Data values;
    NodeQueue* next;
};

// Dummy values untuk direturn
Data dummyQueue = {"-----", -1, "-----", -1, "-----", "-----"};
pair<Data, int> dummyStack = make_pair(dummyQueue, -1);

// Inisialisasi
NodeStack* StackHead = NULL;
NodeQueue* QueueHead = NULL;
NodeQueue* QueueTail = NULL;

/* Fungsi-fungsi untuk queue */
// enqueue
void enqueue(Data insertedData) {
    NodeQueue* newNode = new NodeQueue;
    newNode->values = insertedData;
    if(QueueHead == NULL) {
        QueueHead = newNode;
        QueueTail = newNode;
        QueueHead->next = QueueTail->next = NULL;
    }
    else {
        QueueTail->next = newNode;
        QueueTail = newNode;
        QueueTail->next = NULL;
    }
}

// dequeue
void dequeue() {
    if(QueueHead == NULL) cout << "Antrean kosong!\n";
    else {
        Data front = QueueHead->values;
        NodeQueue* oldHead = QueueHead;
        if(oldHead->next == NULL) QueueHead = QueueTail = NULL;
        else QueueHead = oldHead->next;
        delete oldHead;
        cout << "\nNama: " << front.nama << '\n';
        cout << "NIU: " << front.NIU << '\n';
        cout << "Jam: " << front.jam << '\n';
        cout << "Durasi: " << front.durasi << '\n';
        cout << "Keperluan: " << front.alasan << '\n';
        cout << "Ruangan: " << front.ruangan << '\n';
    }
}

// displayQueue
void displayQueue() {
    if(QueueHead == NULL) cout << "Antrean kosong!\n";
    else {
        NodeQueue* cur = QueueHead;
        while(cur != NULL) {
            cout << '\n';
            Data curData = cur->values;
            cout << "Nama: " << curData.nama << '\n';
            cout << "NIU: " << curData.NIU << '\n';
            cout << "Jam: " << curData.jam << '\n';
            cout << "Durasi: " << curData.durasi << '\n';
            cout << "Keperluan: " << curData.alasan << '\n';
            cout << "Ruangan: " << curData.ruangan << '\n';
            cur = cur->next;
        }
    }
}

// getFront
Data getFront() {
    if(QueueHead == NULL) {
        cout << "Antrean kosong!\n";
        return dummyQueue;
    }
    return QueueHead->values;
}

/* Fungsi-fungsi untuk stack */
// push
void push(Data insertedData, int insertedDataStatus) {
    NodeStack* newNode = new NodeStack;
    newNode->values = insertedData;
    newNode->status = insertedDataStatus;
    if(StackHead == NULL) {
        StackHead = newNode;
        StackHead->next = NULL;
    }
    else {
        newNode->next = StackHead;
        StackHead = newNode;
    }
}

// pop
void pop() {
    if(StackHead == NULL) cout << "Riwayat kosong!\n";
    else {
        Data top = StackHead->values;
        int topStatus = StackHead->status;
        NodeStack* oldHead = StackHead;
        if(oldHead->next == NULL) StackHead = NULL;
        else StackHead = oldHead->next;
        delete oldHead;
        cout << "\nNama: " << top.nama << '\n';
        cout << "NIU: " << top.NIU << '\n';
        cout << "Jam: " << top.jam << '\n';
        cout << "Durasi: " << top.durasi << '\n';
        cout << "Keperluan: " << top.alasan << '\n';
        cout << "Ruangan: " << top.ruangan << '\n';
        cout << "Status: " << ((topStatus == 0) ? "Ditolak" : "Diterima") << '\n';
    }
}

// displayStack
void displayStack() {
    if(StackHead == NULL) cout << "Riwayat kosong!\n";
    else {
        NodeStack* cur = StackHead;
        while(cur != NULL) {
            cout << '\n';
            Data curData = cur->values;
            int curStatus = cur->status;
            cout << "Nama: " << curData.nama << '\n';
            cout << "NIU: " << curData.NIU << '\n';
            cout << "Jam: " << curData.jam << '\n';
            cout << "Durasi: " << curData.durasi << '\n';
            cout << "Keperluan: " << curData.alasan << '\n';
            cout << "Ruangan: " << curData.ruangan << '\n';
            cout << "Status: " << ((curStatus == 0) ? "Ditolak" : "Diterima") << '\n';
            cur = cur->next;
        }
    }
}

// getTop
pair<Data, int> getTop() {
    if(StackHead == NULL) {
        cout << "Riwayat kosong!\n";
        return dummyStack;
    }
    return make_pair(StackHead->values, StackHead->status);
}

int main() {
    cout << "\tSISTEM PEMINJAMAN RUANG KELAS\t\n";
    while(true) {
        int userType;
        cout << "\nMasuk sebagai?\n0: Peminjam\n1: Admin\n2: Exit\n";
        cin >> userType;
        if(userType == 0) {
            while(true) {
                int query;
                cout << "\nMau lakukan apa?\n0: Buat permohonan peminjaman\n1: Lihat status peminjaman terakhir\n2: Exit\n";
                cin >> query;
                if(query == 0) {
                    Data studentData;
                    cout << "Masukkan nama Anda: ";
                    cin >> studentData.nama;
                    cout << "Masukkan NIU Anda: ";
                    cin >> studentData.NIU;
                    cout << "Masukkan jam mulai peminjaman: ";
                    cin >> studentData.jam;
                    cout << "Masukkan durasi peminjaman (dalam menit): ";
                    cin >> studentData.durasi;
                    cout << "Masukkan keperluan peminjaman: ";
                    cin >> studentData.alasan;
                    cout << "Masukkan ruangan yang akan dipinjam: ";
                    cin >> studentData.ruangan;
                    enqueue(studentData);
                    cout << "Permohonan berhasil ditambahkan!\n";
                }
                else if(query == 1) {
                    if(StackHead == NULL) {
                        if(QueueHead == NULL) cout << "Tidak ada permohonan peminjaman!\n";
                        else cout << "Permohonan Anda masih diproses.\n";
                    }
                    else {
                        cout << "Riwayat peminjaman terakhir:\n";
                        pop();
                    }
                }
                else break;
            }
            
        }
        else if(userType == 1) {
            int query;
            cout << "\nMau lakukan apa?\n0: Lihat antrean peminjaman\n1: Proses peminjaman ruangan\n2: Lihat riwayat peminjaman\n3: Exit\n";
            cin >> query;
            if(query == 0) {
                cout << "Antrean peminjaman: ";
                displayQueue();
                cout << "Antrean berhasil ditampilkan.\n";
            }
            else if(query == 1) {
                if(QueueHead == NULL) cout << "Tidak ada permohonan peminjaman!\n";
                else {
                    cout << "\nTerima permohonan ini?\n";
                    Data front = getFront();
                    dequeue();
                    int response;
                    cout << "\n0: Tidak\n1: Ya\n";
                    cin >> response;
                    push(front, response);
                    cout << "Permohonan berhasil disimpan ke riwayat.\n";
                }
            }
            else if(query == 2) {
                cout << "Riwayat peminjaman: ";
                displayStack();
                cout << "Riwayat berhasil ditampilkan.\n";
            }
            else break;
        }
        else break;
    }
    return 0;
}