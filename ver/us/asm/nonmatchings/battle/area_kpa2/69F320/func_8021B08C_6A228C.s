.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B08C_6A228C
/* 6A228C 8021B08C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A2290 8021B090 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 6A2294 8021B094 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 6A2298 8021B098 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A229C 8021B09C 80620002 */  lb        $v0, 2($v1)
/* 6A22A0 8021B0A0 00023040 */  sll       $a2, $v0, 1
/* 6A22A4 8021B0A4 00C23021 */  addu      $a2, $a2, $v0
/* 6A22A8 8021B0A8 000630C0 */  sll       $a2, $a2, 3
/* 6A22AC 8021B0AC 00C23021 */  addu      $a2, $a2, $v0
/* 6A22B0 8021B0B0 80620003 */  lb        $v0, 3($v1)
/* 6A22B4 8021B0B4 00063080 */  sll       $a2, $a2, 2
/* 6A22B8 8021B0B8 14400002 */  bnez      $v0, .L8021B0C4
/* 6A22BC 8021B0BC 00C2001A */   div      $zero, $a2, $v0
/* 6A22C0 8021B0C0 0007000D */  break     7
.L8021B0C4:
/* 6A22C4 8021B0C4 2401FFFF */   addiu    $at, $zero, -1
/* 6A22C8 8021B0C8 14410004 */  bne       $v0, $at, .L8021B0DC
/* 6A22CC 8021B0CC 3C018000 */   lui      $at, 0x8000
/* 6A22D0 8021B0D0 14C10002 */  bne       $a2, $at, .L8021B0DC
/* 6A22D4 8021B0D4 00000000 */   nop
/* 6A22D8 8021B0D8 0006000D */  break     6
.L8021B0DC:
/* 6A22DC 8021B0DC 00003012 */   mflo     $a2
/* 6A22E0 8021B0E0 8C82000C */  lw        $v0, 0xc($a0)
/* 6A22E4 8021B0E4 0C0B2026 */  jal       evt_set_variable
/* 6A22E8 8021B0E8 8C450000 */   lw       $a1, ($v0)
/* 6A22EC 8021B0EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A22F0 8021B0F0 24020002 */  addiu     $v0, $zero, 2
/* 6A22F4 8021B0F4 03E00008 */  jr        $ra
/* 6A22F8 8021B0F8 27BD0018 */   addiu    $sp, $sp, 0x18
