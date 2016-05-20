import {Component, View} from 'angular2/core';

@Component({
  	selector: 'meal-detail',
  	styleUrls: [
        'lib/semantic.min.css',
    ],
  	templateUrl: 'meal_detail/meal-detail.html'
})

export class MealDetail {

  constructor() {
    console.info('Meal details');
  }

}
