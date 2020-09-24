.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MoveBattleCamOver
/* 17D4E8 8024EC08 3C028028 */  lui       $v0, 0x8028
/* 17D4EC 8024EC0C 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17D4F0 8024EC10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D4F4 8024EC14 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D4F8 8024EC18 8C85000C */  lw        $a1, 0xc($a0)
/* 17D4FC 8024EC1C 14400010 */  bnez      $v0, .L8024EC60
/* 17D500 8024EC20 24020002 */   addiu    $v0, $zero, 2
/* 17D504 8024EC24 8CA50000 */  lw        $a1, ($a1)
/* 17D508 8024EC28 0C0B1EAF */  jal       get_variable
/* 17D50C 8024EC2C 00000000 */   nop      
/* 17D510 8024EC30 3C03800E */  lui       $v1, 0x800e
/* 17D514 8024EC34 2463C070 */  addiu     $v1, $v1, -0x3f90
/* 17D518 8024EC38 8C6400C4 */  lw        $a0, 0xc4($v1)
/* 17D51C 8024EC3C 3C01802A */  lui       $at, 0x802a
/* 17D520 8024EC40 A422F29E */  sh        $v0, -0xd62($at)
/* 17D524 8024EC44 3C018028 */  lui       $at, 0x8028
/* 17D528 8024EC48 AC200CE4 */  sw        $zero, 0xce4($at)
/* 17D52C 8024EC4C 10800004 */  beqz      $a0, .L8024EC60
/* 17D530 8024EC50 24020002 */   addiu    $v0, $zero, 2
/* 17D534 8024EC54 0C0B0F41 */  jal       restart_script
/* 17D538 8024EC58 00000000 */   nop      
/* 17D53C 8024EC5C 24020002 */  addiu     $v0, $zero, 2
.L8024EC60:
/* 17D540 8024EC60 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D544 8024EC64 03E00008 */  jr        $ra
/* 17D548 8024EC68 27BD0018 */   addiu    $sp, $sp, 0x18
