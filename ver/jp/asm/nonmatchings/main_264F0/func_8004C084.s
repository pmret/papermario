.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004C084
/* 27484 8004C084 9082009A */  lbu       $v0, 0x9a($a0)
/* 27488 8004C088 30420004 */  andi      $v0, $v0, 4
/* 2748C 8004C08C 10400003 */  beqz      $v0, .L8004C09C
/* 27490 8004C090 24020001 */   addiu    $v0, $zero, 1
/* 27494 8004C094 0801302A */  j         .L8004C0A8
/* 27498 8004C098 A48000A6 */   sh       $zero, 0xa6($a0)
.L8004C09C:
/* 2749C 8004C09C 94A30004 */  lhu       $v1, 4($a1)
/* 274A0 8004C0A0 A0820055 */  sb        $v0, 0x55($a0)
/* 274A4 8004C0A4 A48300A6 */  sh        $v1, 0xa6($a0)
.L8004C0A8:
/* 274A8 8004C0A8 9082009A */  lbu       $v0, 0x9a($a0)
/* 274AC 8004C0AC 30420008 */  andi      $v0, $v0, 8
/* 274B0 8004C0B0 10400003 */  beqz      $v0, .L8004C0C0
/* 274B4 8004C0B4 24020001 */   addiu    $v0, $zero, 1
/* 274B8 8004C0B8 08013033 */  j         .L8004C0CC
/* 274BC 8004C0BC A08000A8 */   sb       $zero, 0xa8($a0)
.L8004C0C0:
/* 274C0 8004C0C0 90A30008 */  lbu       $v1, 8($a1)
/* 274C4 8004C0C4 A0820056 */  sb        $v0, 0x56($a0)
/* 274C8 8004C0C8 A08300A8 */  sb        $v1, 0xa8($a0)
.L8004C0CC:
/* 274CC 8004C0CC 9082009A */  lbu       $v0, 0x9a($a0)
/* 274D0 8004C0D0 30420010 */  andi      $v0, $v0, 0x10
/* 274D4 8004C0D4 10400003 */  beqz      $v0, .L8004C0E4
/* 274D8 8004C0D8 24020001 */   addiu    $v0, $zero, 1
/* 274DC 8004C0DC 03E00008 */  jr        $ra
/* 274E0 8004C0E0 A48000A4 */   sh       $zero, 0xa4($a0)
.L8004C0E4:
/* 274E4 8004C0E4 94A30006 */  lhu       $v1, 6($a1)
/* 274E8 8004C0E8 A0820054 */  sb        $v0, 0x54($a0)
/* 274EC 8004C0EC 03E00008 */  jr        $ra
/* 274F0 8004C0F0 A48300A4 */   sh       $v1, 0xa4($a0)
