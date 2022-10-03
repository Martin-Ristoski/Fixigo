#include <iostream>
using namespace std;

//function prototypes
void temperature_sprouting(float);
void temperature_growth(float);
void moisture_message(float);
void electrical_conductivity_message(float);
void ph_message(float);
void nitrogen_message(float);
void potassium_message(float);
void phosphorus_message(float, float);
void tds_message(float);

//global variables for temperature
    const int minmin_soiltemp_sprouting=7;
    const int maxmin_soiltemp_sprouting=10;
    const int minoptimal_soiltemp_sprouting=18;
    const int maxoptimal_soiltemp_sprouting=20;
    const int minoptimal_soiltemp_growth=15;
    const int maxoptimal_soiltemp_growth=19;
    const int stop_clubens_growth=29;
    const int stop_growth=42;

//global variables for moisture
    const int min_optimal_moisture=75;
    const int max_optimal_moisture=80;

//global variables for electrical conductivity
    const int warning_electrical_conductivity=1500;

//global variables for ph
    const float min_optimal_ph=5.5;
    const int max_optimal_ph=7;

//global variables for nitrogen
    const int low_nitrogen=10;
    const int medium_nitrogen=20;
    const int high_nitrogen=30;

//global variables for potassium
    const int verylow_potassium=75;
    const int low_potassium=150;
    const int medium_potassium=250;
    const int high_potassium=800;

//global variables for phosphorus
    const int low_phosphorus_neutralacid=20;
    const int medium_phosphorus_neutralacid=40;
    const int high_phosphorus_neutralacid=100;
    const int low_phosphorus_alkaline=10;
    const int medium_phosphorus_alkaline=20;
    const int high_phosphorus_alkaline=40;

//global variables for total dissolved solids
    const int min_optimal_tds=1400;
    const int max_optimal_tds=2100;


//global variable for final message
    string str="";
int main()
{
    //Parameters
    float temperature, moisture, electrical_conductivity, nitrogen,
    potassium, phosphorus, ph, salinitiy, total_dissolved_solids,
    air_temperature, air_humidity;



    //Connect to database

    int sprouting;
    cout<<"Dali piperkata e vo faza na niknenje ili proniknuvanje? (da-1, ne-0)"<<endl;
    cin>>sprouting;

    if(sprouting!=0 && sprouting!=1){
        str+="Invalid Input\n";
        cout<<str<<endl;
        return 0;
    }


//temperature
    cout<<"Input Soil Temperature:"<<endl;
    cin>>temperature;

    if(sprouting==1)
            temperature_sprouting(temperature);
    else if(sprouting==0)
        temperature_growth(temperature);

/*
//moisture
    cout<<"Input Moisture:"<<endl;
    cin>>moisture;
    moisture_message(moisture);


//electrical condutivity
    cout<<"Input Electrical Conductivity:"<<endl;
    cin>>electrical_conductivity;
    electrical_conductivity_message(electrical_conductivity);


//ph
    cout<<"Input PH(Acidity):"<<endl;
    cin>>ph;
    ph_message(ph);


//nitrogen
    cout<<"Input Nitrogen:"<<endl;
    cin>>nitrogen;
    nitrogen_message(nitrogen);


//potassium
    cout<<"Input Potassium:"<<endl;
    cin>>potassium;
    potassium_message(potassium);


//phosphorus
    cout<<"Input Phosphorus:"<<endl;
    cin>>phosphorus;
    phosphorus_message(phosphorus, ph);


//salinity
    cout<<"Input Salinity:"<<endl;
    cin>>salinitiy;


//total dissolved solids
    cout<<"Input Total Dissolved Solids:"<<endl;
    cin>>total_dissolved_solids;
    tds_message(total_dissolved_solids);



//air temperature
    cout<<"Input Air Temperature:"<<endl;
    cin>>air_temperature;


//air humidity
    cout<<"Input Air Humidity:"<<endl;
    cin>>air_humidity;
*/


    cout<<str<<endl;
    return 0;
}

void temperature_sprouting(float temperature){
    if(temperature<minmin_soiltemp_sprouting)
        str+="Temperaturata na pochvata e pod bioloshki minimum za uspeshno niknenje. (Bioloshki minimalna temperatura e 7-10 C)\n";
    else if(temperature>=minmin_soiltemp_sprouting && temperature<=maxmin_soiltemp_sprouting)
        str+="Temperaturata na pochvata e bioloshki minimum za uspeshno niknenje. (Bioloshki minimalna temperatura e 7-10 C)\n";
    else if(temperature>maxmin_soiltemp_sprouting && temperature<minoptimal_soiltemp_sprouting)
        str+="Temperaturata na pochvata e pod optimalnata temperatura za niknenje. (Optimalnata temperatura e 18-20 C)\n";
    else if(temperature>=minoptimal_soiltemp_sprouting && temperature<=maxoptimal_soiltemp_sprouting)
        str+="Temperaturata na pochvata e optimalna za niknenje. (Optimalnata temperatura e 18-20 C)\n";
    else if(temperature>maxoptimal_soiltemp_sprouting)
        str+="Temperaturata na pochvata e nad optimalnata temperatura za niknenje. (Optimalnata temperatura e 18-20 C)\n";
    else
        str+="Error";

}

void temperature_growth(float temperature){
    if(temperature<minoptimal_soiltemp_growth)
        str+="Temperaturata na pochvata e pod optimalnata za rast na kompirot. (Optimalnata temperatura e 15-19 C)\n";
    else if(temperature>=minoptimal_soiltemp_growth && temperature<=maxoptimal_soiltemp_growth)
        str+="Temperaturata na pochvata e optimalna za rast na kompirot. (Optimalnata temperatura e 15-19 C)\n";
    else if(temperature>maxoptimal_soiltemp_growth && temperature<stop_clubens_growth)
        str+="Temperaturata na pochvata e nad optimalnata za rast na kompirot. (Optimalnata temperatura e 15-19 C)\n";
    else if(temperature>=stop_clubens_growth && temperature<=stop_growth)
        str+="Temperaturata na pochvata e povisoka od 28 C, pri shto prestanuva formiranjeto na klubenite. (Prekin na formiranje na klubeni >28 C)\n";
    else if(temperature>stop_growth)
        str+="Temperaturata na pochvata e povisoka od 42 C, pri shto vegetacijata potpolno prestanuva (Prekin na vegetacija >42)\n";
    else
        str+="Error";
}


void moisture_message(float moisture){
    if(moisture<min_optimal_moisture)
        str+="Vlazhnnosta na pochvata e pod optimalata. (Optimalna vlazhnost e 75%-80%)\n";
    else if(moisture>=min_optimal_moisture && moisture<=max_optimal_moisture)
        str+="Vlazhnosta na pochvata e optimalna. (Optimalna vlazhnost e 75%-80%)\n";
    else if(moisture>max_optimal_moisture)
        str+="Vlazhnnosta na pochvata e nad optimalata. (Optimalna vlazhnost e 75%-80%)\n";
    else
        str+="Error";
}


void electrical_conductivity_message(float electrical_conductivity){
    if(electrical_conductivity>=warning_electrical_conductivity)
        str+="Elektrichnata sprovodnost e nad optimalata, namaluvajkji go prinosot za 75%-90%.\n";
}


void ph_message(float ph){
    if(ph<5.5)
        str+="Pochvata e premnogu kisela, izvrshi kalifikacija. (Optimalna ph vrednost 5.5-7.0)\n";
    else if(ph>7)
        str+="Pochvata e premnogu bazna(alkalna). (Optimalna ph vrednost 5.5-7.0)\n";
    else
        str+="PH vrednosta na pochvata e optimalna. (Optimalna ph vrednost 5.5-7.0)\n";
}


void nitrogen_message(float nitrogen){
    if(nitrogen<low_nitrogen)
        str+="Niska zastapenost na nitraten azot vo pochvata (Niska zastapenost <10 ppm (mg/kg))\n";
    else if(nitrogen>=low_nitrogen && nitrogen<=medium_nitrogen)
        str+="Sredna zastapenost na nitraten azot vo pochvata (Sredna zastapenost 10-20 ppm (mg/kg))\n";
    else if(nitrogen>medium_nitrogen && nitrogen<=high_nitrogen)
        str+="Visoka zastapenost na nitraten azot vo pochvata (Visoka zastapenost 21-30 ppm (mg/kg))\n";
    else if(nitrogen>high_nitrogen)
        str+="Prekumerna zastapenost na nitraten azot vo pochvata (Prekumerna zastapenost >30 ppm (mg/kg))\n";
    else
        str+="Error";
}


void potassium_message(float potassium){
    if(potassium<verylow_potassium)
        str+="Preniska zastapenost na kalium vo pochvata (Preniska zastapenost <75 ppm (mg/kg))\n";
    else if(potassium>=verylow_potassium && potassium<=low_potassium)
        str+="Niska zastapenost na kalium vo pochvata (Niska zastapenost 75-150 ppm (mg/kg))\n";
    else if(potassium>low_potassium && potassium<=medium_potassium)
        str+="Sredna zastapenost na kalium vo pochvata (Sredna zastapenost 151-250 ppm (mg/kg))\n";
    else if(potassium>medium_potassium && potassium<=high_potassium)
        str+="Visoka zastapenost na kalium vo pochvata (Visoka zastapenost 251-800 ppm (mg/kg))\n";
    else if(potassium>high_potassium)
        str+="Prekumerna zastapenost na kalium vo pochvata (Prekumerna zastapenost >800 ppm (mg/kg))\n";
    else
        str+="Error";
}


void phosphorus_message(float phosphorus, float ph){
    if(ph<=7){ //bray p1 method
        if(phosphorus<low_phosphorus_neutralacid)
        str+="Niska zastapenost na fosfor vo pochvata (Niska zastapenost <20 ppm (mg/kg))\n";
    else if(phosphorus>=low_phosphorus_neutralacid && phosphorus<=medium_phosphorus_neutralacid)
        str+="Sredna zastapenost na fosfor vo pochvata (Sredna zastapenost 20-40 ppm (mg/kg))\n";
    else if(phosphorus>medium_phosphorus_neutralacid && phosphorus<=high_phosphorus_neutralacid)
        str+="Visoka zastapenost na fosfor vo pochvata (Visoka zastapenost 41-100 ppm (mg/kg))\n";
    else if(phosphorus>high_phosphorus_neutralacid)
        str+="Prekumerna zastapenost na fosfor vo pochvata (Prekumerna zastapenost >100 ppm (mg/kg))\n";
    else
        str+="Error";
    }
    else if(ph>7){ //olsen method
        if(phosphorus<low_phosphorus_alkaline)
        str+="Niska zastapenost na fosfor vo pochvata (Niska zastapenost <10 ppm (mg/kg))\n";
    else if(phosphorus>=low_phosphorus_alkaline && phosphorus<=medium_phosphorus_alkaline)
        str+="Sredna zastapenost na fosfor vo pochvata (Sredna zastapenost 10-20 ppm (mg/kg))\n";
    else if(phosphorus>medium_phosphorus_alkaline && phosphorus<=high_phosphorus_alkaline)
        str+="Visoka zastapenost na fosfor vo pochvata (Visoka zastapenost 21-40 ppm (mg/kg))\n";
    else if(phosphorus>high_phosphorus_alkaline)
        str+="Prekumerna zastapenost na fosfor vo pochvata (Prekumerna zastapenost >40 ppm (mg/kg))\n";
    else
        str+="Error";
    }
}


void tds_message(float total_dissolved_solids){
    if(total_dissolved_solids<min_optimal_tds)
        str+="Vkupniot broj na rastvoreni cvrsti materii(TDS) e pod optimalata. (Optimalna TDS vrednost 1400-2100)";
    else if(total_dissolved_solids>=min_optimal_tds && total_dissolved_solids<=max_optimal_tds)
        str+="Vkupniot broj na rastvoreni cvrsti materii(TDS) e optimalen. (Optimalna TDS vrednost 1400-2100)";
    else if(total_dissolved_solids>max_optimal_tds)
        str+="Vkupniot broj na rastvoreni cvrsti materii(TDS) e nad optimalata. (Optimalna TDS vrednost 1400-2100)";
    else
        str+="Error";
}
