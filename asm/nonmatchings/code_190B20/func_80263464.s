.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80263464
/* 191D44 80263464 3C028011 */  lui       $v0, 0x8011
/* 191D48 80263468 8042F292 */  lb        $v0, -0xd6e($v0)
/* 191D4C 8026346C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 191D50 80263470 1C40000D */  bgtz      $v0, .L802634A8
/* 191D54 80263474 AFBF0010 */   sw       $ra, 0x10($sp)
/* 191D58 80263478 3C02800E */  lui       $v0, %hi(gBattleState)
/* 191D5C 8026347C 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 191D60 80263480 3C03800E */  lui       $v1, 0x800e
/* 191D64 80263484 8C63C4DC */  lw        $v1, -0x3b24($v1)
/* 191D68 80263488 3C01800E */  lui       $at, 0x800e
/* 191D6C 8026348C AC22C4E4 */  sw        $v0, -0x3b1c($at)
/* 191D70 80263490 3C01800E */  lui       $at, 0x800e
/* 191D74 80263494 AC23C4D8 */  sw        $v1, -0x3b28($at)
/* 191D78 80263498 0C090464 */  jal       func_80241190
/* 191D7C 8026349C 2404001B */   addiu    $a0, $zero, 0x1b
/* 191D80 802634A0 08098D2B */  j         .L802634AC
/* 191D84 802634A4 24020001 */   addiu    $v0, $zero, 1
.L802634A8:
/* 191D88 802634A8 0000102D */  daddu     $v0, $zero, $zero
.L802634AC:
/* 191D8C 802634AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 191D90 802634B0 03E00008 */  jr        $ra
/* 191D94 802634B4 27BD0018 */   addiu    $sp, $sp, 0x18
