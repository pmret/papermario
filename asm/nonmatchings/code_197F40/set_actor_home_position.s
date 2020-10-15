.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_actor_home_position
/* 198600 80269D20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 198604 80269D24 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 198608 80269D28 4485A000 */  mtc1      $a1, $f20
/* 19860C 80269D2C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 198610 80269D30 4486B000 */  mtc1      $a2, $f22
/* 198614 80269D34 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 198618 80269D38 4487C000 */  mtc1      $a3, $f24
/* 19861C 80269D3C AFBF0010 */  sw        $ra, 0x10($sp)
/* 198620 80269D40 0C09A75B */  jal       get_actor
/* 198624 80269D44 00000000 */   nop      
/* 198628 80269D48 E4540138 */  swc1      $f20, 0x138($v0)
/* 19862C 80269D4C E456013C */  swc1      $f22, 0x13c($v0)
/* 198630 80269D50 E4580140 */  swc1      $f24, 0x140($v0)
/* 198634 80269D54 8FBF0010 */  lw        $ra, 0x10($sp)
/* 198638 80269D58 D7B80028 */  ldc1      $f24, 0x28($sp)
/* 19863C 80269D5C D7B60020 */  ldc1      $f22, 0x20($sp)
/* 198640 80269D60 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 198644 80269D64 03E00008 */  jr        $ra
/* 198648 80269D68 27BD0030 */   addiu    $sp, $sp, 0x30
