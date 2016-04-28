import {Component, View} from 'angular2/core';

@Component({
  selector: 'learning-angular-2'
})

@View({
  templateUrl: 'learning-angular-2.html'
})

export class LearningAngular2 {

  constructor() {
    console.info('LearningAngular2 Component Mounted Successfully');
  }

}
