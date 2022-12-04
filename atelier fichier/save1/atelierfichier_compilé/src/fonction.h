typedef struct 
{
char nom[20];
char prenom[20];
char username[20];
char password[20];
int role;
}inscri;

char ajouter(inscri p,char filename [],char nom[],char prenom[],char username[],char password[] ,int role);
int login(char username[], char password[], char filename[]);

