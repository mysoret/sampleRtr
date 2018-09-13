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
      const options = {
        selectableRecognitionLanguages : ['English', 'French', 'German', 'Italian', 'Polish', 'PortugueseBrazilian',
                                          'Russian', 'ChineseSimplified', 'ChineseTraditional', 'Japanese', 'Korean',
                                          'Spanish'],
        recognitionLanguages : ['English'],

        licenseFileName : 'AbbyyRtrSdk.license'
      };

      this.abbyyRTR.startTextCapture(options)
      .then((res: any) => alert(JSON.stringify(res)))
      .catch((error: any) => alert(JSON.stringify(error)));

  }

}
