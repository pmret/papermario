.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F9C0
/* 3ADC0 8005F9C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3ADC4 8005F9C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3ADC8 8005F9C8 8C82000C */  lw        $v0, 0xc($a0)
/* 3ADCC 8005F9CC 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3ADD0 8005F9D0 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3ADD4 8005F9D4 90460000 */  lbu       $a2, ($v0)
/* 3ADD8 8005F9D8 3C02800E */  lui       $v0, %hi(D_800DAAB8)
/* 3ADDC 8005F9DC 2442AAB8 */  addiu     $v0, $v0, %lo(D_800DAAB8)
/* 3ADE0 8005F9E0 00062840 */  sll       $a1, $a2, 1
/* 3ADE4 8005F9E4 00A62821 */  addu      $a1, $a1, $a2
/* 3ADE8 8005F9E8 00052880 */  sll       $a1, $a1, 2
/* 3ADEC 8005F9EC 00A62821 */  addu      $a1, $a1, $a2
/* 3ADF0 8005F9F0 000528C0 */  sll       $a1, $a1, 3
/* 3ADF4 8005F9F4 0C019FC9 */  jal       func_80067F24
/* 3ADF8 8005F9F8 00A22821 */   addu     $a1, $a1, $v0
/* 3ADFC 8005F9FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AE00 8005FA00 03E00008 */  jr        $ra
/* 3AE04 8005FA04 27BD0018 */   addiu    $sp, $sp, 0x18
