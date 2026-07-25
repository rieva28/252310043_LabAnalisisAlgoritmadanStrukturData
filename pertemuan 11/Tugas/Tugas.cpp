#include <iostream>
#include <climits>
using namespace std;

#define V 7               // Jumlah simpul pada graph
#define INF 99999         // Nilai yang merepresentasikan tidak adanya jalur

// Daftar nama lokasi
string lokasi[V] = {
    "Cibinong",
    "Cileubet",
    "Tanah Sareal",
    "Bogor Tengah",
    "Bogor Utara",
    "Baranangsiang",
    "Tajur"
};

// Fungsi untuk mencetak lintasan terpendek
void tampilkanJalur(int parent[], int tujuan)
{
    // Berhenti jika telah mencapai simpul awal
    if (parent[tujuan] == -1)
    {
        cout << lokasi[tujuan];
        return;
    }

    // Menampilkan lintasan sebelumnya
    tampilkanJalur(parent, parent[tujuan]);

    // Menampilkan simpul berikutnya
    cout << " -> " << lokasi[tujuan];
}

// Implementasi Algoritma Dijkstra
void dijkstra(int graph[V][V], int awal, int akhir)
{
    int jarak[V];          // Menyimpan jarak minimum
    bool dikunjungi[V];    // Status simpul yang telah diproses
    int parent[V];         // Menyimpan lintasan

    // Inisialisasi nilai awal
    for (int i = 0; i < V; i++)
    {
        jarak[i] = INF;
        dikunjungi[i] = false;
        parent[i] = -1;
    }

    // Titik awal memiliki jarak nol
    jarak[awal] = 0;

    // Proses pencarian lintasan
    for (int i = 0; i < V - 1; i++)
    {
        int minimum = INF;
        int posisi = -1;

        // Memilih simpul dengan jarak terkecil
        for (int j = 0; j < V; j++)
        {
            if (!dikunjungi[j] && jarak[j] < minimum)
            {
                minimum = jarak[j];
                posisi = j;
            }
        }

        // Menghentikan proses apabila tidak ada simpul yang dapat dipilih
        if (posisi == -1)
            break;

        dikunjungi[posisi] = true;

        // Memperbarui jarak ke simpul yang terhubung
        for (int k = 0; k < V; k++)
        {
            if (!dikunjungi[k] &&
                graph[posisi][k] != INF &&
                jarak[posisi] != INF &&
                jarak[posisi] + graph[posisi][k] < jarak[k])
            {
                jarak[k] = jarak[posisi] + graph[posisi][k];
                parent[k] = posisi;
            }
        }
    }

    // Menampilkan hasil pencarian
    cout << "Rute terpendek dari "
         << lokasi[awal] << " menuju "
         << lokasi[akhir] << " adalah:\n";

    tampilkanJalur(parent, akhir);

    cout << "\nTotal bobot = "
         << jarak[akhir] << endl;
}

int main()
{
    int graph[V][V];

    // Inisialisasi matriks graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Relasi antar lokasi sesuai studi kasus
    graph[0][1] = 1; // Cibinong -> Cileubet
    graph[0][4] = 1; // Cibinong -> Bogor Utara
    graph[1][2] = 1; // Cileubet -> Tanah Sareal
    graph[2][3] = 1; // Tanah Sareal -> Bogor Tengah
    graph[3][6] = 1; // Bogor Tengah -> Tajur
    graph[4][5] = 1; // Bogor Utara -> Baranangsiang
    graph[5][6] = 1; // Baranangsiang -> Tajur

    // Menjalankan algoritma Dijkstra
    dijkstra(graph, 0, 6);

    return 0;
}
