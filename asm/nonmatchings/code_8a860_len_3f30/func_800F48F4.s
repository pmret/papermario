.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F48F4
/* 8DDA4 800F48F4 3C028011 */  lui       $v0, 0x8011
/* 8DDA8 800F48F8 8042D690 */  lb        $v0, -0x2970($v0)
/* 8DDAC 800F48FC 3C038011 */  lui       $v1, 0x8011
/* 8DDB0 800F4900 8C63D69C */  lw        $v1, -0x2964($v1)
/* 8DDB4 800F4904 3C078011 */  lui       $a3, 0x8011
/* 8DDB8 800F4908 8CE7D650 */  lw        $a3, -0x29b0($a3)
/* 8DDBC 800F490C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8DDC0 800F4910 AFA20010 */  sw        $v0, 0x10($sp)
/* 8DDC4 800F4914 3C028011 */  lui       $v0, 0x8011
/* 8DDC8 800F4918 8C42D648 */  lw        $v0, -0x29b8($v0)
/* 8DDCC 800F491C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8DDD0 800F4920 AFA00014 */  sw        $zero, 0x14($sp)
/* 8DDD4 800F4924 00021080 */  sll       $v0, $v0, 2
/* 8DDD8 800F4928 00621821 */  addu      $v1, $v1, $v0
/* 8DDDC 800F492C 8C640294 */  lw        $a0, 0x294($v1)
/* 8DDE0 800F4930 0C04993B */  jal       draw_string
/* 8DDE4 800F4934 24A50008 */   addiu    $a1, $a1, 8
/* 8DDE8 800F4938 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8DDEC 800F493C 03E00008 */  jr        $ra
/* 8DDF0 800F4940 27BD0020 */   addiu    $sp, $sp, 0x20
