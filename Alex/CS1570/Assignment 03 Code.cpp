//-----------------------------------------------------------------------
// Name: ALEX SHAW 	 Date: 09-15-14
// File: hw3.cpp     Class: Section CS 1570, Section B
//------------------------------------------------------------------------
// Program Description:
// Guides two users through a series of menus to
// determine their injuries; the program then determines which
// injury requires more immediate medical attention.

#include <iostream>
using namespace std;
int main()
{
  const short CEREBRAL_CONTUSION = 9;	              //Initialize constants
  const short DISK_RUPTURE = 7;			                //for ISS
  const short BROKEN_RADIUS = 3;
  const short INTESTINAL_DISTRESS = 2;
  const short BROKEN_NECK = 6;
  const short BURNT_TOE_HAIR = 1;
  const short PERMANENT_SMILEY_FACE = 3;
  const short FLAIL_CHEST = 4;
  const short EARLOBE_GASTROPHILOLOGY = 5;
  const short ALCOHOL_POISONING = 2;
  const short FRACTURED_FEMUR = 3;
  const short NAIL_FUNGUS = 0;
  const short ALTERED_EGO = 4;
  const short ALIEN_IMPLANATATION = 8;
  const short BBQD_RIBS = 7;
  const short DEFORMED_PLASTIC_SURGERY = 1;

  						                        //Initialize input vars
  short region_choice;				        //Holds user’s choice
  short sub_region_choice;        		//at respective menus
  short injury_choice;
  string patient_one_name;				    //Holds the respective
  string patient_two_name;				    //patients’ names


 						                                        //Initialize output vars
  short patient_one_iss;	                          //Holds ISS score of
  short patient_two_iss;	                          //patients
  string patient_one_injury;				                //Holds names of patients’
  string patient_two_injury;				                // respective injuries


  cout << "/t/tWelcome to Dr. Eloe’s ISS program!";
  cout << "/n/nEnter the first patient’s name:	";	    //Enter and store
  cin >> patient_one_name;					                    //name to display later

  do
  {
    cout << "/n In which body region does" << patient_one_name ;
             << "have an injury? Please enter one of the following";
             << "numbers";
    cout << "/n/n/t/t/t/tBody Regions" << endl;	    	//Display a menu
    cout << "/t/t/t1. Head & Neck" << endl;		        // of areas for injuries
    cout << "/t/t/t2. Torso" << endl;
    cout << "/t/t/t3. Extremity" << endl;
    cout << "/t/t/t4. Not listed" << endl;
    cout << "/t/t/tRegion: "; << endl;
    cint >> region_choice;
  } while ( !(region_choice >= 1 && region_choice <= 4))     //Validates input


  if (!(region_choice != 1))					                     //If the user chose
  {                                                        // Head & Neck,
    do                                                     // show sub regions
    {
      cout << "/n/nIn what head and neck sub region does";
               << patient_one_name << "have an injury? Please enter one";
               << "of the following numbers"; << endl;

      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1. Head"<< endl;
      cout << "/t/t/t2. Neck"<< endl;
      cout << "/t/t/t3. Face"<< endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 3))  //Validates
                                                                    //input

    if (!(sub_region_choice != 1))				                //If the user chose
    {                                                     // Head, display
      do                                                  // injuries
      {
        cout << "/n/nWhat head injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Cerebral Contusion" << endl;
        cout << "/t/t/t/t2. Earlobe gastrophilology" << endl;
        cout << "/t/t/t/t3. Altered ego" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 3))        //Validate
                                                                    //input

      if (!(injury_choice != 1))				                //Assign injury name
        {							                                  // and ISS to vars,
           patient_one_iss = CEREBRAL_CONTUSION;				// depending on
           patient_one_injury = "Cerebral contusion";		// injury chosen
        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = EARLOBE_GASTROPHILOLOGY;
           patient_one_injury = "Earlobe gastrophilology";
        }

      else if (!(injury_choice != 3))
        {
           patient_one_iss = ALTERED_EGO;
           patient_one_injury = "Altered Ego";
        }

    }

    else if (!(sub_region_choice != 2))			                  //If user chose
    {							                                            // Neck, display
      do                                                      // injuries
      {
        cout << "/n/nWhat neck injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Broken neck" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice == 1))                              //Validate
                                                                    //input

      if (!(injury_choice != 1))				              //If the user chose
        {							                                // Broken Neck,
           patient_one_iss = BROKEN_NECK;
           patient_one_injury = "Broken neck";
        }



    }

   else  if (!(sub_region_choice != 3))			           //If the user chose
    {							                                     // Face, display
      do                                               // injuries
      {
        cout << "/n/nWhat face injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Permanent Smiley Face" << endl;
        cout << "/t/t/t/t2. Deformed plastic surgery" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))
    }

      if (!(injury_choice != 1))				                   //Assign injury name
        {							                                     // and ISS to vars,
           patient_one_iss = PERMANENT_SMILEY_FACE;				 // depending on
           patient_one_injury = "Permanent Smiley Face";	 // injury chosen
        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = DEFORM_PLAST_SURG;
           patient_one_injury = "Deformed Plastic Surgery";
        }
  }



  else if (!(region_choice != 2))					                  //If the user chose
  {								                                          // Torso, display
    do                                                      // sub regions
    {
      cout << "/n/nIn what sub region of the torso does";
               << patient_one_name << "have an injury? Please";
               << "enter one of the following numbers";
               << endl;
      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1. Back" << endl;
      cout << "/t/t/t2. Chest" << endl;
      cout << "/t/t/t3. Abdomen" << endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 3))  //Validate
                                                                    // input

    if (!(sub_region_choice != 1)				                 //If the user chose
    {							                                       // Back, display
      do                                                 // injuries
      {
        cout << "/n/nWhat back injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Disk rupture" << endl;
        cout << "/t/t/t/t2. BBQd ribs" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && inury_choice <= 2))    //Validate input


      if (!(injury_choice != 1))				                   //Assign ISS and
        {							                                     // injury name to
           patient_one_iss = DISK_RUPTURE;				         // vars
           patient_one_injury = "Disk Rupture";
        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = BBQD_RIBS;
           patient_one_injury = "BBQd Ribs";
        }

    }

    else if (!(sub_region_choice != 2)			         //If the user chose
    {							                                   // Chest, display
      do                                             // injuries
      {
        cout << "/n/nWhat chest injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Flail chest" << endl;
        cout << "/t/t/t/t2. Alien implantation" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))    //Validate
                                                                // input

      if (!(injury_choice != 1))				                //Assign ISS and
        {							                                  //injury name to vars
           patient_one_iss = FLAIL_CHEST;
           patient_one_injury = "Flail chest";
        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = ALIEN_IMPL;
           patient_one_injury = "Alien Implantation";
        }

    }

    else if (!(sub_region_choice != 3)			            //If the user chose
    {							                                      // Abdomen, display
      do                                                // injuries
      {
        cout << "/n/nWhat abdominal injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Intestinal distress" << endl;
        cout << "/t/t/t/t2. Alcohol poisoning" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))    //Validate
                                                                // input


      if (!(injury_choice != 1))				                //Stors ISS and injury
        {							                                  //name as vars
           patient_one_iss = INTESTINAL_DISTRESS;
           patient_one_injury = "Intestinal distress";

        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = ALCOHOL_POISN;
           patient_one_injury = "Alcohol Poisoning";
        }

    }
   }

  else if (!(region_choice != 3))					              //If the user chose
  {								                                      // Extremity, display
    do                                                  // sub regions
    {
      cout << "/n/nIn what extremity sub region does";
               << patient_one_name << "have an injury? Please";
               << "enter one of the following numbers";
               << endl;
      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1.Leg" << endl;
      cout << "/t/t/t2. Arm" << endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 2))   //Validate
                                                                     //input

    if (!(sub_region_choice != 1))				              //If the user chose
    {                                                   // Leg, display
      do                                                // injuries
      {
        cout << "/n/nWhat leg injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Burnt toe hair" << endl;
        cout << "/t/t/t/t2. Fractured femur" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))      //Validates
                                                                  // input

      if (!(injury_choice != 1))
        {
           patient_one_iss = BURNT_TOE_HAIR;
           patient_one_injury = "Burnt toe hair";
        }

      else if (!(injury_choice != 2))
        {
           patient_one_iss = FRACT_FEMUR;
           patient_one_injury = "Fractured femur";
        }

    }

    else if (!(sub_region_choice != 2)			             //If the user chose
    {							                                       // Arm, display
      do                                                 // injuries
      {
        cout << "/n/nWhat arm injury does";
                 << patient_one_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Broken radius" << endl;
        cout << "/t/t/t/t2. Fingernail fungus" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))      //Validates
                                                                  // input

      if (!(injury_choice != 1))	                        //Assign ISS and
      {							                                      // injury to vars
         patient_one_iss = BROKE_RADIUS;
         patient_one_injury = "Broken radius";
      }

      else if (!(injury_choice != 2))
      {
         patient_one_iss = NAIL_FUNG;
         patient_one_injury = "Fingernail fungus";
      }

    }
  }

  else if (!(region_choice != 4))				               //If the user chose
  {							                                       // Not Listed from
    patient_one_iss = -1;						                   // Region menu,
  }                                                    // their ISS is -1

  cout << "/n/nEnter the second patient’s name:	";	    //Enter and store
  cin >> patient_two_name;					                    //name to display later

  do                                           //Seek out patient two's injury
  {
    cout << "/n In which body region does" << patient_two_name ;
             << "have an injury? Please enter one of the following";
             << "numbers";
    cout << "/n/n/t/t/t/tBody Regions" << endl;	    	//Display a menu
    cout << "/t/t/t1. Head & Neck" << endl;		        // of areas for injuries
    cout << "/t/t/t2. Torso" << endl;
    cout << "/t/t/t3. Extremity" << endl;
    cout << "/t/t/t4. Not listed" << endl;
    cout << "/t/t/tRegion: "; << endl;
    cint >> region_choice;
  } while ( !(region_choice >= 1 && region_choice <= 4))     //Validates input


  if (!(region_choice != 1))					                     //If the user chose
  {                                                        // Head & Neck,
    do                                                     // show sub regions
    {
      cout << "/n/nIn what head and neck sub region does";
               << patient_two_name << "have an injury? Please enter one";
               << "of the following numbers"; << endl;

      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1. Head"<< endl;
      cout << "/t/t/t2. Neck"<< endl;
      cout << "/t/t/t3. Face"<< endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 3))  //Validates
                                                                    //input

    if (!(sub_region_choice != 1))				                //If the user chose
    {                                                     // Head, display
      do                                                  // injuries
      {
        cout << "/n/nWhat head injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Cerebral Contusion" << endl;
        cout << "/t/t/t/t2. Earlobe gastrophilology" << endl;
        cout << "/t/t/t/t3. Altered ego" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 3))        //Validate
                                                                    //input

      if (!(injury_choice != 1))				                //Assign injury name
        {							                                  // and ISS to vars,
           patient_two_iss = CEREBRAL_CONTUSION;				// depending on
           patient_two_injury = "Cerebral contusion";		// injury chosen
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = EARLOBE_GASTROPHILOLOGY;
           patient_two_injury = "Earlobe gastrophilology";
        }

      else if (!(injury_choice != 3))
        {
           patient_two_iss = ALTERED_EGO;
           patient_two_injury = "Altered Ego";
        }

    }

    else if (!(sub_region_choice != 2))			                  //If user chose
    {							                                            // Neck, display
      do                                                      // injuries
      {
        cout << "/n/nWhat neck injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Broken neck" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice == 1))                              //Validate
                                                                    //input

      if (!(injury_choice != 1))				              //If the user chose
        {							                                // Broken Neck,
           patient_two_iss = BROKEN_NECK;
           patient_two_injury = "Broken neck";
        }



    }

   else  if (!(sub_region_choice != 3))			           //If the user chose
    {							                                     // Face, display
      do                                               // injuries
      {
        cout << "/n/nWhat face injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Permanent Smiley Face" << endl;
        cout << "/t/t/t/t2. Deformed plastic surgery" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))
    }

      if (!(injury_choice != 1))				                   //Assign injury name
        {							                                     // and ISS to vars,
           patient_two_iss = PERMANENT_SMILEY_FACE;				 // depending on
           patient_two_injury = "Permanent Smiley Face";	 // injury chosen
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = DEFORM_PLAST_SURG;
           patient_two_injury = "Deformed Plastic Surgery";
        }
  }



  else if (!(region_choice != 2))					                  //If the user chose
  {								                                          // Torso, display
    do                                                      // sub regions
    {
      cout << "/n/nIn what sub region of the torso does";
               << patient_two_name << "have an injury? Please";
               << "enter one of the following numbers";
               << endl;
      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1. Back" << endl;
      cout << "/t/t/t2. Chest" << endl;
      cout << "/t/t/t3. Abdomen" << endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 3))  //Validate
                                                                    // input

    if (!(sub_region_choice != 1)				                 //If the user chose
    {							                                       // Back, display
      do                                                 // injuries
      {
        cout << "/n/nWhat back injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Disk rupture" << endl;
        cout << "/t/t/t/t2. BBQd ribs" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && inury_choice <= 2))    //Validate input


      if (!(injury_choice != 1))				                   //Assign ISS and
        {							                                     // injury name to
           patient_two_iss = DISK_RUPTURE;				         // vars
           patient_two_injury = "Disk Rupture";
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = BBQD_RIBS;
           patient_two_injury = "BBQd Ribs";
        }

    }

    else if (!(sub_region_choice != 2)			         //If the user chose
    {							                                   // Chest, display
      do                                             // injuries
      {
        cout << "/n/nWhat chest injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Flail chest" << endl;
        cout << "/t/t/t/t2. Alien implantation" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))    //Validate
                                                                // input

      if (!(injury_choice != 1))				                //Assign ISS and
        {							                                  //injury name to vars
           patient_two_iss = FLAIL_CHEST;
           patient_two_injury = "Flail chest";
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = ALIEN_IMPL;
           patient_two_injury = "Alien Implantation";
        }

    }

    else if (!(sub_region_choice != 3)			            //If the user chose
    {							                                      // Abdomen, display
      do                                                // injuries
      {
        cout << "/n/nWhat abdominal injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Intestinal distress" << endl;
        cout << "/t/t/t/t2. Alcohol poisoning" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))    //Validate
                                                                // input


      if (!(injury_choice != 1))				                //Stors ISS and injury
      {							                                  //name as vars
         patient_two_iss = INTESTINAL_DISTRESS;
         patient_two_injury = "Intestinal distress";

      }

      else if (!(injury_choice != 2))
      {
         patient_two_iss = ALCOHOL_POISN;
         patient_two_injury = "Alcohol Poisoning";
      }

    }
  }

  else if (!(region_choice != 3))					              //If the user chose
  {								                                      // Extremity, display
    do                                                  // sub regions
    {
      cout << "/n/nIn what extremity sub region does";
               << patient_two_name << "have an injury? Please";
               << "enter one of the following numbers";
               << endl;
      cout << "/n/n/t/t/t/tSub Regions" << endl;
      cout << "/t/t/t1.Leg" << endl;
      cout << "/t/t/t2. Arm" << endl;
      cout << "/t/t/tSub Region: "; << endl;
      cin >> sub_region_choice;
    } while ( !(sub_region_choice >= 1 && sub_region_choice <= 2))   //Validate
                                                                     //input

    if (!(sub_region_choice != 1))				              //If the user chose
    {                                                   // Leg, display
      do                                                // injuries
      {
        cout << "/n/nWhat leg injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Burnt toe hair" << endl;
        cout << "/t/t/t/t2. Fractured femur" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))      //Validates
                                                                  // input

      if (!(injury_choice != 1))
        {
           patient_two_iss = BURNT_TOE_HAIR;
           patient_two_injury = "Burnt toe hair";
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = FRACT_FEMUR;
           patient_two_injury = "Fractured femur";
        }

    }

    else if (!(sub_region_choice != 2)			             //If the user chose
    {							                                       // Arm, display
      do                                                 // injuries
      {
        cout << "/n/nWhat arm injury does";
                 << patient_two_name << "have? Please";
                 << "enter the number"; << endl;
        cout << "/n/n/t/t/t/tInjuries" << endl;
        cout << "/t/t/t/t1. Broken radius" << endl;
        cout << "/t/t/t/t2. Fingernail fungus" << endl;
        cout << "/t/t/t/tInjury: " << endl;
        cin >> injury_choice;
      } while ( !(injury_choice >= 1 && injury_choice <= 2))      //Validates
                                                                  // input

      if (!(injury_choice != 1))	                          //Assign ISS and
        {							                                      // injury to vars
           patient_two_iss = BROKE_RADIUS;
           patient_two_injury = "Broken radius";
        }

      else if (!(injury_choice != 2))
        {
           patient_two_iss = NAIL_FUNG;
           patient_two_injury = "Fingernail fungus";
        }

     }
  }

  else if (!(region_choice != 4))				               //If the user chose
  {							                                       // Not Listed from
    patient_two_iss = -1;						                   // Region menu,
  }                                                    // their ISS is -1

  if (patient_one_iss > patient_two_iss)                 //Determine which ISS
  {                                                      // is larger. That
    cout << "Dr. Eloe will see" << patient_one_name <<   // patient will be seen
         << "first." << endl;                            // first
  }

  else if (patient_two_iss > patient_one_iss)
  {
    cout << "Dr. Eloe will see" << patient_two_name <<
         << "first." << endl;
  }

  else if (patient_one_iss == patient_two_iss)          //If both ISS values are
  {                                                     // equal, the name with
    if (patient_one_name > patient_two_iss)             // the smaller ASCII
    {                                                   // value will be seen.
      cout << "Dr. Eloe will see" << patient_one_name <<
           << "first." << endl;
    }

    else if (patient_two_name > patient_one_iss)
    {
      cout << "Dr. Eloe will see" << patient_two_name <<
           << "first." << endl;
    }

    else if (patient_two_name == patient_one_iss)             //If both patients
    {                                                         // have the same
       cout << "Dr. Eloe will see" << patient_one_name <<     // name, choose
            << "first." << endl;                              // first user
    }
  }

Return 0;
}
