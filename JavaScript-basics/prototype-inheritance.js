let stage = [];

const Entity = function(name, health, attack) {
  this.index = stage.length
  this.name = name
  this.health = health;
  this.attack = attack;

  stage.push(this);
}

Entity.prototype.getHealth = function() {
  return this.health;
}

Entity.prototype.getAttack = function() {
  return this.attack;
}

Entity.prototype.getIndex = function() {
  return this.index;
}

Entity.prototype.getName = function() {
  return this.name;
}

const Goblin = new Entity('Goblin', 10, 2);

Goblin.prototype = Object.create(Entity.prototype);

Goblin.attackTarget = function(index) {
  let target = stage[index];

  console.log('Hack!');
  console.log('Slash!');
  console.log('Chop!');
  target.health = target.health - this.attack * 3;

  console.log(`${target.getName()} health is now: ${target.health}.`);
  console.log(' ');
}

const Player = new Entity('James', 15, 5);

Player.prototype = Object.create(Entity.prototype);

Player.attackTarget = function(index) {
  let target = stage[index];
  target.health = target.health - this.attack;

  console.log('Slash!');

  console.log(`${target.getName()} health is now: ${target.getHealth()}.`);
  console.log(' ')
}

Player.attackTarget(0);

Goblin.attackTarget(1);

Player.attackTarget(0);

console.log('Battle complete!');

