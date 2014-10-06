//Programmer: LOUIE BERTONCIN   Date: 9/15/2014
//File: H3 Injury Prioritizer   Class: CS 1570, Section D

#include <iostream>
using namespace std;

int main()
{
  const short ALCOHOL_POISONING = 2;
  const short ALIEN_IMPLANTATION = 8;
  const short ALTERED_EGO = 4;
  const short BBQD_RIBS = 7;
  const short BROKEN_NECK = 6;
  const short BROKEN_RADIUS = 3;
  const short BURNED_TOE_HAIR = 1;
  const short CEREBRAL_CONTUSION = 9;
  const short DEFORMED_PLASTIC_SURGERY = 1;
  const short DISK_RUPTURE = 7;
  const short EARLOBE_GASTROPHILOLOGY = 5;
  const short FLAIL_CHEST = 4;
  const short FRACTURED_FEMUR = 3;
  const short INTESTINAL_DISTRESS = 2;
  const short NAIL_FUNGUS = 0;
  const short PERMANENT_SMILEY_FACE = 3;

  short menu1_choice;
  short menu2_choice;
  short menu3_choice;

  string patient1_name;
  short patient1_score;

  string patient2_name;
  short patient2_score;

  bool ppl_switch = true;
  string person_name;

  cout << "Welcome to the Injury Prioritizer!" << endl << endl;
  cout << "Please input the two patients you'd like to prioritize..." << endl;
  cout << "Patient 1's name: ";
  cin >> patient1_name;
  cout << "Patient 2's name: ";
  cin >> patient2_name;

  do
  {
    (ppl_switch ? person_name = patient1_name : person_name = patient2_name);
    do
    {
      cout << "\n\nNow specify " << person_name << "'s injury!" << endl << endl;
      cout << "1. Head and Neck" << endl;
      cout << "2. Torso" << endl;
      cout << "3. Extremity" << endl;
      cout << "4. Not Listed" << endl << endl;
      cout << "Please choose a number from above: ";
      cin >> menu1_choice;
    } while(menu1_choice < 1 || menu1_choice > 4);

    if (menu1_choice == 1)
    {
      do
      {
      cout << "Where is the head or neck injury located?" << endl << endl;
      cout << "1. Face" << endl;
      cout << "2. Head" << endl;
      cout << "3. Neck" << endl << endl;
      cout << "Please chooose a number from above: ";
      cin >> menu2_choice;
      } while (menu2_choice < 1 || menu2_choice > 3);
      if (menu2_choice == 1)
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Permanent Smiley Face" << endl;
          cout << "2. Deformed Plastic Surgery (melting)" << endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have a Permanent Smiley \
Face." << endl;
          (ppl_switch ? patient1_score = PERMANENT_SMILEY_FACE :
            patient2_score = PERMANENT_SMILEY_FACE);
        }
        else
        {
          cout << "You chose " << person_name << " to have a Deformed Plastic \
Surgery (melting)" << endl;
          (ppl_switch ? patient1_score = DEFORMED_PLASTIC_SURGERY :
            patient2_score = DEFORMED_PLASTIC_SURGERY);
        }
      }
      else if (menu2_choice == 2)
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Cerebral Contusion" << endl;
          cout << "2. Earlobe gastrophilology (super-hyper lobe \
contusional inflamation)" << endl;
          cout << "3. Altered Ego (A grade of D in cs 1570)"<< endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 3);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have a Cerebral \
Contusion" << endl;
          (ppl_switch ? patient1_score = CEREBRAL_CONTUSION :
            patient2_score = CEREBRAL_CONTUSION);
        }
        else if (menu3_choice == 2)
        {
          cout << "You chose " << person_name << " to have an Earlobe \
gastrophilology (super-hyper lobe contusional inflamation)" << endl;
          (ppl_switch ? patient1_score = EARLOBE_GASTROPHILOLOGY :
            patient2_score = EARLOBE_GASTROPHILOLOGY);
        }
        else
        {
          cout << "You chose " << person_name << " to have an Altered Ego"
            << endl;
          (ppl_switch ? patient1_score = ALTERED_EGO :
            patient2_score = ALTERED_EGO);
        }
      }
      else
      {
        cout << "\nThe patient must have a Broken Neck" << endl;
        (ppl_switch ? patient1_score = BROKEN_NECK :
          patient2_score = BROKEN_NECK);
      }
    }
    else if (menu1_choice == 2)
    {
      do
      {
        cout << "Where is the torso injury located?" << endl << endl;
        cout << "1. Abdomen" << endl;
        cout << "2. Back" << endl;
        cout << "3. Chest" << endl << endl;
        cout << "Please chooose a number from above: ";
        cin >> menu2_choice;
      } while (menu2_choice < 1 || menu2_choice > 3);
      if (menu2_choice == 1)
      {
        do
        {
        cout << "What kind of injury is it?" << endl << endl;
        cout << "1. Intestinal Distress" << endl;
        cout << "2. Alcohol Poisoning" << endl << endl;
        cout << "Please chooose a number from above: ";
        cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have Intestinal \
Distress" << endl;
          (ppl_switch ? patient1_score = INTESTINAL_DISTRESS :
            patient2_score = INTESTINAL_DISTRESS);
        }
        else
        {
          cout << "You chose " << person_name << " to have Alcohol Poisoning"
            << endl;
          (ppl_switch ? patient1_score = ALCOHOL_POISONING :
            patient2_score = ALCOHOL_POISONING);
        }
      }
      else if (menu2_choice == 2)
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Disk Rupture" << endl;
          cout << "2. BBQd Ribs" << endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have a Disk Rupture"
            << endl;
          (ppl_switch ? patient1_score = DISK_RUPTURE :
            patient2_score = DISK_RUPTURE);
        }
        else
        {
          cout << "You chose " << person_name << " to have BBQd Ribs" << endl;
          (ppl_switch ? patient1_score = BBQD_RIBS :
            patient2_score = BBQD_RIBS);
        }
      }
      else
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Alien Implantation" << endl;
          cout << "2. Flail Chest" << endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have an Alien \
Implantation" << endl;
          (ppl_switch ? patient1_score = ALIEN_IMPLANTATION :
            patient2_score = ALIEN_IMPLANTATION);
        }
        else
        {
          cout << "You chose " << person_name << " to have a Flail Chest"
            << endl;
          (ppl_switch ? patient1_score = FLAIL_CHEST :
            patient2_score = FLAIL_CHEST);
        }
      }
    }
    else if (menu1_choice == 3)
    {
      do
      {
        cout << "Where is the extremity injury located?" << endl << endl;
        cout << "1. Arm" << endl;
        cout << "2. Leg" << endl << endl;
        cout << "Please chooose a number from above: ";
        cin >> menu2_choice;
      } while(menu2_choice < 1 || menu2_choice > 2);
      if (menu2_choice == 1)
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Broken Radius" << endl;
          cout << "2. Finger Nail Fungus" << endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have a Broken Radius"
            << endl;
          (ppl_switch ? patient1_score = BROKEN_RADIUS :
            patient2_score = BROKEN_RADIUS);
        }
        else
        {
          cout << "You chose " << person_name << " to have Finger Nail Fungus"
            << endl;
          (ppl_switch ? patient1_score = NAIL_FUNGUS :
            patient2_score = NAIL_FUNGUS);
        }
      }
      else
      {
        do
        {
          cout << "What kind of injury is it?" << endl << endl;
          cout << "1. Fractured Femur" << endl;
          cout << "2. Burned Toe Hair" << endl << endl;
          cout << "Please chooose a number from above: ";
          cin >> menu3_choice;
        } while (menu3_choice < 1 || menu3_choice > 2);
        if (menu3_choice == 1)
        {
          cout << "You chose " << person_name << " to have a Fractured Femur"
            << endl;
          (ppl_switch ? patient1_score = FRACTURED_FEMUR :
            patient2_score = FRACTURED_FEMUR);
        }
        else
        {
          cout << "You chose " << person_name << " to have Burned Toe Hair"
            << endl;
          (ppl_switch ? patient1_score = BURNED_TOE_HAIR :
            patient2_score = BURNED_TOE_HAIR);
        }
      }
    }
    else
    {
      (ppl_switch ? patient1_score = -1 : patient2_score = -1);
    }

    ppl_switch = !ppl_switch;

  } while (!ppl_switch);

  if (patient1_score == patient2_score)
  {
    cout << "\nThe doctor should see " << (patient1_name < patient2_name ?
      patient1_name : patient2_name) << " first" << endl;
  }
  else if (patient1_score > patient2_score)
  {
    cout << "\nThe doctor should see " << patient1_name << " first" << endl;
  }
  else
  {
    cout << "\nThe doctor should see " << patient2_name << " first" << endl;
  }

  return 0;
}
