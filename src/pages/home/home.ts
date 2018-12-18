import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { AbbyyRTR } from '@ionic-native/abbyy-rtr';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  constructor(public navCtrl: NavController,
              private abbyyRTR: AbbyyRTR) {

  }

  openRTR() {
     /** const options = {
        selectableRecognitionLanguages : ['English', 'French', 'German', 'Italian', 'Polish', 'PortugueseBrazilian',
                                          'Russian', 'ChineseSimplified', 'ChineseTraditional', 'Japanese', 'Korean',
                                          'Spanish'],
        recognitionLanguages : ['English'],

        licenseFileName : 'AbbyyRtrSdk.license'
      };

      this.abbyyRTR.startTextCapture(options)
      .then((res: any) => alert(JSON.stringify(res)))
      .catch((error: any) => alert(JSON.stringify(error))); **/


      this.abbyyRTR.startDataCapture({
        customDataCaptureScenario : {
          name : 'Scan_VIN_Plate',
          description : '',
          recognitionLanguages : ['English'],
          fields : [ {
            regEx : '[0-9A-HJ-NPR-Z]{8}[0-9X][0-9A-HJ-NPR-Z]{2}[0-9]{6}'
          } ]
        },
        licenseFileName : 'AbbyyRtrSdk.license',
        isStopButtonVisible : false,
      })
      .then((res: any) => {
      console.log(JSON.stringify(res));
      alert(res['dataFields'][0].text);
    }, (error) => {
      console.log('~~~ RTR capture failed ~~~~ Error description - ' + JSON.stringify(error));
      alert(JSON.stringify(error));
    });

  }

}
