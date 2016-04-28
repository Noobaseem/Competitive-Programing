import {Component, View} from 'angular2/core';

@Component({
  selector: 'meal-detail'
})

@View({
  templateUrl: 'meal_detail/meal-detail.html'
})

export class MealDetail {

  constructor() {
    console.info('Meal details');
  }

}
