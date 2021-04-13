.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006AF5C
/* 4635C 8006AF5C 03E09021 */  addu      $s2, $ra, $zero
/* 46360 8006AF60 3C0A800E */  lui       $t2, %hi(D_800D9F60)
/* 46364 8006AF64 254A9F60 */  addiu     $t2, $t2, %lo(D_800D9F60)
/* 46368 8006AF68 01445021 */  addu      $t2, $t2, $a0
/* 4636C 8006AF6C 8D490000 */  lw        $t1, ($t2)
/* 46370 8006AF70 11200027 */  beqz      $t1, .L8006B010
/* 46374 8006AF74 00000000 */   nop
/* 46378 8006AF78 8D2B0008 */  lw        $t3, 8($t1)
/* 4637C 8006AF7C 8D2C0010 */  lw        $t4, 0x10($t1)
/* 46380 8006AF80 016C082A */  slt       $at, $t3, $t4
/* 46384 8006AF84 10200022 */  beqz      $at, .L8006B010
/* 46388 8006AF88 00000000 */   nop
/* 4638C 8006AF8C 8D2D000C */  lw        $t5, 0xc($t1)
/* 46390 8006AF90 01AB6821 */  addu      $t5, $t5, $t3
/* 46394 8006AF94 01AC001A */  div       $zero, $t5, $t4
/* 46398 8006AF98 15800002 */  bnez      $t4, .L8006AFA4
/* 4639C 8006AF9C 00000000 */   nop
/* 463A0 8006AFA0 0007000D */  break     7
.L8006AFA4:
/* 463A4 8006AFA4 2401FFFF */   addiu    $at, $zero, -1
/* 463A8 8006AFA8 15810004 */  bne       $t4, $at, .L8006AFBC
/* 463AC 8006AFAC 3C018000 */   lui      $at, 0x8000
/* 463B0 8006AFB0 15A10002 */  bne       $t5, $at, .L8006AFBC
/* 463B4 8006AFB4 00000000 */   nop
/* 463B8 8006AFB8 0006000D */  break     6
.L8006AFBC:
/* 463BC 8006AFBC 00006810 */   mfhi     $t5
/* 463C0 8006AFC0 8D2C0014 */  lw        $t4, 0x14($t1)
/* 463C4 8006AFC4 24010004 */  addiu     $at, $zero, 4
/* 463C8 8006AFC8 01A10018 */  mult      $t5, $at
/* 463CC 8006AFCC 00006812 */  mflo      $t5
/* 463D0 8006AFD0 018D6021 */  addu      $t4, $t4, $t5
/* 463D4 8006AFD4 8D4D0004 */  lw        $t5, 4($t2)
/* 463D8 8006AFD8 AD8D0000 */  sw        $t5, ($t4)
/* 463DC 8006AFDC 256A0001 */  addiu     $t2, $t3, 1
/* 463E0 8006AFE0 AD2A0008 */  sw        $t2, 8($t1)
/* 463E4 8006AFE4 8D2A0000 */  lw        $t2, ($t1)
/* 463E8 8006AFE8 8D4B0000 */  lw        $t3, ($t2)
/* 463EC 8006AFEC 11600008 */  beqz      $t3, .L8006B010
/* 463F0 8006AFF0 00000000 */   nop
/* 463F4 8006AFF4 0C01AC67 */  jal       func_8006B19C
/* 463F8 8006AFF8 01202021 */   addu     $a0, $t1, $zero
/* 463FC 8006AFFC 00405021 */  addu      $t2, $v0, $zero
/* 46400 8006B000 01402821 */  addu      $a1, $t2, $zero
/* 46404 8006B004 3C048009 */  lui       $a0, %hi(D_80094638)
/* 46408 8006B008 0C01AC55 */  jal       func_8006B154
/* 4640C 8006B00C 24844638 */   addiu    $a0, $a0, %lo(D_80094638)
.L8006B010:
/* 46410 8006B010 02400008 */  jr        $s2
/* 46414 8006B014 00000000 */   nop
.L8006B018:
/* 46418 8006B018 3C013000 */  lui       $at, 0x3000
/* 4641C 8006B01C 01014824 */  and       $t1, $t0, $at
/* 46420 8006B020 00094F02 */  srl       $t1, $t1, 0x1c
/* 46424 8006B024 240A0001 */  addiu     $t2, $zero, 1
/* 46428 8006B028 152AFFC0 */  bne       $t1, $t2, .L8006AF2C
/* 4642C 8006B02C 00000000 */   nop
/* 46430 8006B030 24090001 */  addiu     $t1, $zero, 1
/* 46434 8006B034 AF490018 */  sw        $t1, 0x18($k0)
/* 46438 8006B038 8F5B0118 */  lw        $k1, 0x118($k0)
/* 4643C 8006B03C 3C012000 */  lui       $at, 0x2000
/* 46440 8006B040 0361D825 */  or        $k1, $k1, $at
/* 46444 8006B044 1000FFB3 */  b         .L8006AF14
/* 46448 8006B048 AF5B0118 */   sw       $k1, 0x118($k0)
