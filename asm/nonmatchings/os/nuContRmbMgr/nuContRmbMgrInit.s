.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContRmbMgrInit
/* 3B08C 8005FC8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B090 8005FC90 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B094 8005FC94 0000202D */  daddu     $a0, $zero, $zero
/* 3B098 8005FC98 24050002 */  addiu     $a1, $zero, 2
/* 3B09C 8005FC9C 0080182D */  daddu     $v1, $a0, $zero
.L8005FCA0:
/* 3B0A0 8005FCA0 3C01800B */  lui       $at, 0x800b
/* 3B0A4 8005FCA4 00230821 */  addu      $at, $at, $v1
/* 3B0A8 8005FCA8 A0251D46 */  sb        $a1, 0x1d46($at)
/* 3B0AC 8005FCAC 3C01800B */  lui       $at, 0x800b
/* 3B0B0 8005FCB0 00230821 */  addu      $at, $at, $v1
/* 3B0B4 8005FCB4 A0201D47 */  sb        $zero, 0x1d47($at)
/* 3B0B8 8005FCB8 3C01800B */  lui       $at, 0x800b
/* 3B0BC 8005FCBC 00230821 */  addu      $at, $at, $v1
/* 3B0C0 8005FCC0 A4241D44 */  sh        $a0, 0x1d44($at)
/* 3B0C4 8005FCC4 24840001 */  addiu     $a0, $a0, 1
/* 3B0C8 8005FCC8 2C820004 */  sltiu     $v0, $a0, 4
/* 3B0CC 8005FCCC 1440FFF4 */  bnez      $v0, .L8005FCA0
/* 3B0D0 8005FCD0 2463000A */   addiu    $v1, $v1, 0xa
/* 3B0D4 8005FCD4 3C048009 */  lui       $a0, 0x8009
/* 3B0D8 8005FCD8 0C0180FC */  jal       nuSiCallBackAdd
/* 3B0DC 8005FCDC 24843D00 */   addiu    $a0, $a0, 0x3d00
/* 3B0E0 8005FCE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B0E4 8005FCE4 03E00008 */  jr        $ra
/* 3B0E8 8005FCE8 27BD0018 */   addiu    $sp, $sp, 0x18
