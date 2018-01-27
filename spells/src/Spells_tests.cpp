#include <criterion/criterion.h>

#include "Spells.hpp"

Test(check_spells, class_exists)
{
    Spells* spells = nullptr;
    cr_assert_null(spells);
}

Test(check_spells, class_constructor_exists)
{
    Spells* spells = new Spells;
    cr_assert_not_null(spells);
    delete spells;
}

Test(check_spells, class_get_left_spell_exists)
{
    Spells* spells = new Spells;
    
    Spells::Type type = spells->left();
    cr_assert_eq(Spells::SPELL_NONE, type);
    
    delete spells;
}

Test(check_spells, class_get_right_spell_exists)
{
    Spells* spells = new Spells;
    
    Spells::Type type = spells->right();
    cr_assert_eq(Spells::SPELL_NONE, type);
    
    delete spells;
}

Test(check_spells, class_get_move_left_spell_exists)
{
    Spells* spells = new Spells;
    
    spells->move_left();
    
    delete spells;
}

Test(check_spells, class_get_move_left_with_no_spell)
{
    Spells* spells = new Spells;
    
    spells->move_left();
    cr_assert_eq(Spells::SPELL_NONE, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_get_move_right_spell_exists)
{
    Spells* spells = new Spells;
    
    spells->move_right();
    
    delete spells;
}

Test(check_spells, class_get_move_right_with_no_spell)
{
    Spells* spells = new Spells;
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_NONE, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_get_push_spell_exists)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_ELECTRIC);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_SNARE);
    
    spells->push_spell(Spells::SPELL_SWORD);
    spells->push_spell(Spells::SPELL_BOW);
    
    delete spells;
}

Test(check_spells, class_get_remove_spell_exists)
{
    Spells* spells = new Spells;

    spells->remove_spell(Spells::SPELL_FIREBALL);

    delete spells;
}

Test(check_spells, class_get_push_one_spell)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_get_push_one_spell_twice)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_FIREBALL);
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_get_push_two_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_HEAL, spells->right());
    
    delete spells;
}

Test(check_spells, class_get_push_three_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_HEAL, spells->right());
    
    delete spells;
}

Test(check_spells, class_move_left_with_one_spell)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    
    spells->move_left();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_move_right_with_one_spell)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    delete spells;
}

Test(check_spells, class_move_left_with_thow_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_SWORD);
    
    spells->move_left();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_SWORD, spells->right());
    
    delete spells;
}

Test(check_spells, class_move_right_with_thow_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_SWORD);
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_SWORD, spells->right());
    
    delete spells;
}

Test(check_spells, class_move_right_with_three_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    spells->move_left();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->right());
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());

    delete spells;
}

Test(check_spells, class_move_left_with_three_spells)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->move_left();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_HEAL, spells->right());
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    spells->move_right();
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());

    delete spells;
}

Test(check_spells, insert_right_insert_right_insert_right)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->move_right();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_NONE, spells->right());
    
    spells->push_spell(Spells::SPELL_HEAL);
    spells->move_right();
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_HEAL, spells->right());
    
    spells->push_spell(Spells::SPELL_BOW);
    spells->move_right();
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    delete spells;
}

Test(check_spells, complexe01)
{
    Spells* spells = new Spells;

    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->remove_spell(Spells::SPELL_FIREBALL);
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());

    delete spells;
}

Test(check_spells, complexe02)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->move_right();
    spells->remove_spell(Spells::SPELL_HEAL);
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    delete spells;
}

Test(check_spells, complexe03)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->move_right();
    spells->remove_spell(Spells::SPELL_FIREBALL);
    cr_assert_eq(Spells::SPELL_HEAL, spells->left());
    cr_assert_eq(Spells::SPELL_BOW, spells->right());
    
    delete spells;
}

Test(check_spells, complexe04)
{
    Spells* spells = new Spells;
    
    spells->push_spell(Spells::SPELL_FIREBALL);
    spells->push_spell(Spells::SPELL_HEAL);
    spells->push_spell(Spells::SPELL_BOW);
    
    spells->move_right();
    spells->remove_spell(Spells::SPELL_BOW);
    cr_assert_eq(Spells::SPELL_FIREBALL, spells->left());
    cr_assert_eq(Spells::SPELL_HEAL, spells->right());
    
    delete spells;
}


