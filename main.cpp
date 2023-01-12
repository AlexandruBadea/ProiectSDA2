#include <iostream>

using namespace std;

struct student{
    char prenume[15];
    char nume[15];
    float media;
    int nr_restante;
};

struct lista{
    student v;
    lista *urm;
};

lista *adaugare (lista *x, student y){
    lista *n = new lista;
    n->v = y;
    n->urm = x;
    x = n;
    return x;
}

void afisare_lista(lista *x, int nr){
    if(x == NULL)
      cout<<"Lista este goala"<<endl;
    for(int i = 0; i < nr; i++){
        cout<<"["<<i<<"]";
        cout<<"\t Prenume: "<<x->v.prenume<<endl;
        cout<<"\t Nume: "<<x->v.nume<<endl;
        cout<<"\t Media: "<<x->v.media<<endl;
        cout<<"\t Numar restante: "<<x->v.nr_restante<<endl<<endl;

        x = x->urm;
    }
}

lista *sterge_student(lista *primul_element, int pozitie) {
    if (pozitie < 0 || primul_element == NULL) return primul_element;
    lista *p = primul_element;
    if (pozitie == 0) {
        primul_element = primul_element->urm;
    } else {
        for (int i = 0; i < pozitie - 1; i++) {
            p = p->urm;
        }
        p->urm = p->urm->urm;
    }
    return primul_element;
}

void actualizeaza_student(lista *primul_element, int pozitie) {
    if (pozitie < 0 || primul_element == NULL) return;
    lista *p = primul_element;
    for (int i = 0; i < pozitie; i++) {
        p = p->urm;
    }

    student x;
    cout<<"Noile date pentru acest student: "<<endl;
    cout<<"Prenume: "; cin>>x.prenume;
    cout<<"Nume: "; cin>>x.nume;
    cout<<"Media: "; cin>>x.media;
    cout<<"Numar restante: "; cin>>x.nr_restante;
    cout<<endl;
    p->v = x;
}


int main()
{
    int nr_stud;
    student studenti;
    lista *lista_studenti;

    cout<<"Lista ta de studenti este goala. Adauga unul sau mai multi studenti: "<<endl;
    cout<<"Cati studenti vrei sa adaugi: "; cin>> nr_stud;

    for(int i = 0; i < nr_stud; i++){
        cout<<"======= Studentul "<<i<<"======="<<endl;
        cout<<"Prenume: "; cin>>studenti.prenume;
        cout<<"Nume: "; cin>>studenti.nume;
        cout<<"Media: "; cin>>studenti.media;
        cout<<"Numar restante: "; cin>>studenti.nr_restante;
        cout<<"=========================="<<endl<<endl;

        lista_studenti = adaugare(lista_studenti, studenti);
    }

    afisare_lista(lista_studenti, nr_stud);

    cout<<"Optiuni pentru editarea listei: "<<endl;
    cout<<"[1] Stergerea unui student din lista"<<endl;
    cout<<"[2] Actualizarea datelor unui student"<<endl<<endl;

    int optiune, id;
    cout<<"Introdu optiunea pentru editarea listei: ";cin>>optiune;
    cout<<endl;

    switch(optiune){
        case 1:{
            cout<<"[!] Introdu ID-ul studentului pe care vrei sa il stergi: "; cin>> id; cout<<endl;
            lista_studenti = sterge_student(lista_studenti, id);
            cout<<"Afisarea studentilor dupa stergere: "<<endl;
            afisare_lista(lista_studenti, nr_stud-1);
        }
        case 2:{
            cout<<"[!] Introdu ID-ul studentului pe care vrei sa il editezi: "; cin>>id; cout<<endl;
            actualizeaza_student(lista_studenti, id);
            cout<<"Afisarea studentilor dupa editare: "<<endl;
            afisare_lista(lista_studenti, nr_stud);
        }
    }

    return 0;
}
