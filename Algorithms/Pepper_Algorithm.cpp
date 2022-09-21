#include <iostream>
using namespace std;

//function prototypes
void temperature_germination(float);
void temperature_growth(float);
void moisture_message(float);
void electrical_conductivity_message(float);
void ph_message(float);
void nitrogen_message(float);
void potassium_message(float);
void phosphorus_message(float, float);

//global variables for temperature
    const int min_soiltemp_germination=11;
    const int minoptimal_soiltemp_germination=25;
    const int maxoptimal_soiltemp_germination=30;
    const int maxoptimal_soiltemp_growth=25;
    const int minoptimal_soiltemp_growth=16;
    const int zero_growth=0;
    const int wither_growth=10;
    const int death_growth=30;

//global variables for moisture
    const int min_optimal_moisture=75;
    const int max_optimal_moisture=80;

//global variables for electrical conductivity
    const int warning_electrical_conductivity=150000;

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
int main()
{
    //Parameters
    float temperature, moisture, electrical_conductivity, nitrogen,
    potassium, phosphorus, ph, salinitiy, total_dissolved_solids,
    air_temperature, air_humidity;



    //Connect to database

    int germination;
    cout<<"Dali piperkata e vo faza na seenje ili 'rtenje? (da-1, ne-0)"<<endl;
    cin>>germination;

    if(germination!=0 && germination!=1){
        cout<<"Invalid Input"<<endl;
        return 0;
    }


//temperature
    cout<<"Input Soil Temperature:"<<endl;
    cin>>temperature;

    if(germination==1)
            temperature_germination(temperature);
    else if(germination==0)
        temperature_growth(temperature);


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


//air temperature
    cout<<"Input Air Temperature:"<<endl;
    cin>>air_temperature;


//air humidity
    cout<<"Input Air Humidity:"<<endl;
    cin>>air_humidity;


    return 0;
}

void temperature_germination(float temperature){
    if(temperature<min_soiltemp_germination)
        cout<<"Temperaturata na pochvata e pod minimalnata temperatura za seenje i 'rtenje na semeto. (Minimalnata temperatura e 11 C)"<<endl;
    else if(temperature>min_soiltemp_germination-1 && temperature<minoptimal_soiltemp_germination)
        cout<<"Temperaturata na pochvata e pod optimalnata temperatura za seenje i 'rtenje na semeto. (Optimalnata temperatura e 25-30 C)"<<endl;
    else if(temperature>minoptimal_soiltemp_germination-1 && temperature<maxoptimal_soiltemp_germination+1)
        cout<<"Temperaturata na pochvata e optimalna za seenje i 'rtenje na semeto. (Optimalnata temperatura e 25-30 C)"<<endl;
    else
        cout<<"Temperaturata na pochvata e nad optimalnata temperatura za seenje i 'rtenje na semeto. (Optimalnata temperatura e 25-30 C)"<<endl;

}

void temperature_growth(float temperature){
    if(temperature<1)
        cout<<"Temperaturata na pochvata e poniska ili ednakva na 0 C, a mrazot potpolno ja unishtuva piperkata. (Optimalnata temperatura e 16-25 C)"<<endl;
    else if(temperature>zero_growth && temperature<wither_growth)
        cout<<"Temperaturata na pochvata e poniska od 10 C, pri shto doagja do veneenje, zholteenje na lisjata i podocna do zastoj vo rastot na piperkata. (Optimalnata temperatura e 16-25 C)"<<endl;
    else if(temperature>=wither_growth && temperature<minoptimal_soiltemp_growth)
        cout<<"Temperaturata na pochvata e poniska od 16 C, shto potpolno go zaostanuva rastot na piperkata.(Optimalnata temperatura e 16-25 C)"<<endl;
    else if(temperature>=minoptimal_soiltemp_germination && temperature<=maxoptimal_soiltemp_growth)
        cout<<"Temperaturata na pochvata e optimalna za rast i razvoj na piperkata. (Optimalnata temperatura e 16-25 C)"<<endl;
    else if(temperature>maxoptimal_soiltemp_growth && temperature<=death_growth)
        cout<<"Temperaturata na pochvata e nad optimalnata temperatura za rast i razvoj na piperkata. (Optimalnata temperatura e 16-25 C)"<<endl;
    else
        cout<<"Temperaturata na pochvata e nad 30 C, toa negativno deluva na razvojot so namaluvanje na sposobnosta za oploduvanje na cvetovite, nivno opagjanje i otfrlanje na vekje-formiranite plodovi na piperkata. (Optimalnata temperatura e 16-25 C)"<<endl;
}


void moisture_message(float moisture){
    if(moisture<min_optimal_moisture)
        cout<<"Vlazhnnosta na pochvata e pod optimalata. (Optimalna vlazhnost e 75%-80%)"<<endl;
    else if(moisture>=min_optimal_moisture && moisture<=max_optimal_moisture)
        cout<<"Vlazhnosta na pochvata e optimalna. (Optimalna vlazhnost e 75%-80%)"<<endl;
    else
        cout<<"Vlazhnnosta na pochvata e nad optimalata. (Optimalna vlazhnost e 75%-80%)"<<endl;
}


void electrical_conductivity_message(float electrical_conductivity){
    if(electrical_conductivity>=warning_electrical_conductivity)
        cout<<"Elektrichnata sprovodnost e nad optimalata, namaluvajkji go prinosot za 75%-90%."<<endl;
}


void ph_message(float ph){
    if(ph<5.5)
        cout<<"Pochvata e premnogu kisela, izvrshi kalifikacija. (Optimalna ph vrednost 5.5-7.0)"<<endl;
    else if(ph>7)
        cout<<"Pochvata e premnogu bazna(alkalna). (Optimalna ph vrednost 5.5-7.0)"<<endl;
    else
        cout<<"PH vrednosta na pochvata e optimalna. (Optimalna ph vrednost 5.5-7.0)"<<endl;
}


void nitrogen_message(float nitrogen){
    if(nitrogen<low_nitrogen)
        cout<<"Niska zastapenost na nitraten azot vo pochvata (Niska zastapenost <10 ppm (mg/kg))"<<endl;
    else if(nitrogen>=low_nitrogen && nitrogen<=medium_nitrogen)
        cout<<"Sredna zastapenost na nitraten azot vo pochvata (Sredna zastapenost 10-20 ppm (mg/kg))"<<endl;
    else if(nitrogen>medium_nitrogen && nitrogen<=high_nitrogen)
        cout<<"Visoka zastapenost na nitraten azot vo pochvata (Visoka zastapenost 21-30 ppm (mg/kg))"<<endl;
    else
        cout<<"Prekumerna zastapenost na nitraten azot vo pochvata (Prekumerna zastapenost >30 ppm (mg/kg))"<<endl;
}


void potassium_message(float potassium){
    if(potassium<verylow_potassium)
        cout<<"Preniska zastapenost na kalium vo pochvata (Preniska zastapenost <75 ppm (mg/kg))"<<endl;
    else if(potassium>=verylow_potassium && potassium<=low_potassium)
        cout<<"Niska zastapenost na kalium vo pochvata (Niska zastapenost 75-150 ppm (mg/kg))"<<endl;
    else if(potassium>low_potassium && potassium<=medium_potassium)
        cout<<"Sredna zastapenost na kalium vo pochvata (Sredna zastapenost 151-250 ppm (mg/kg))"<<endl;
    else if(potassium>medium_potassium && potassium<=high_potassium)
        cout<<"Visoka zastapenost na kalium vo pochvata (Visoka zastapenost 251-800 ppm (mg/kg))"<<endl;
    else
        cout<<"Prekumerna zastapenost na kalium vo pochvata (Prekumerna zastapenost >800 ppm (mg/kg))"<<endl;
}


void phosphorus_message(float phosphorus, float ph){
    if(ph<=7){ //bray p1 method
        if(phosphorus<low_phosphorus_neutralacid)
        cout<<"Niska zastapenost na fosfor vo pochvata (Niska zastapenost <20 ppm (mg/kg))"<<endl;
    else if(phosphorus>=low_phosphorus_neutralacid && phosphorus<=medium_phosphorus_neutralacid)
        cout<<"Sredna zastapenost na fosfor vo pochvata (Sredna zastapenost 20-40 ppm (mg/kg))"<<endl;
    else if(phosphorus>medium_phosphorus_neutralacid && phosphorus<=high_phosphorus_neutralacid)
        cout<<"Visoka zastapenost na fosfor vo pochvata (Visoka zastapenost 41-100 ppm (mg/kg))"<<endl;
    else
        cout<<"Prekumerna zastapenost na fosfor vo pochvata (Prekumerna zastapenost >100 ppm (mg/kg))"<<endl;
    }
    else if(ph>7){ //olsen method
        if(phosphorus<low_phosphorus_alkaline)
        cout<<"Niska zastapenost na fosfor vo pochvata (Niska zastapenost <10 ppm (mg/kg))"<<endl;
    else if(phosphorus>=low_phosphorus_alkaline && phosphorus<=medium_phosphorus_alkaline)
        cout<<"Sredna zastapenost na fosfor vo pochvata (Sredna zastapenost 10-20 ppm (mg/kg))"<<endl;
    else if(phosphorus>medium_phosphorus_alkaline && phosphorus<=high_phosphorus_alkaline)
        cout<<"Visoka zastapenost na fosfor vo pochvata (Visoka zastapenost 21-40 ppm (mg/kg))"<<endl;
    else
        cout<<"Prekumerna zastapenost na fosfor vo pochvata (Prekumerna zastapenost >40 ppm (mg/kg))"<<endl;
    }
}
