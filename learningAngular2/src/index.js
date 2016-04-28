import {Component, View} from 'angular2/core';
import {bootstrap} from 'angular2/platform/browser';
import {LearningAngular2} from 'learning-angular-2';
import {MealDetail} from 'meal_detail/meal-detail';

@Component({
  selector: 'main'
})

@View({
  directives: [LearningAngular2, MealDetail],
  template: `
  	<learning-angular-2></learning-angular-2>
    <meal-detail></meal-detail>
  `
})

class Main {

}

bootstrap(Main);
