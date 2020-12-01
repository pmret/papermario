.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D60_9C7140
/* 9C7140 80241D60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7144 80241D64 3C058025 */  lui       $a1, %hi(D_80251C58)
/* 9C7148 80241D68 8CA51C58 */  lw        $a1, %lo(D_80251C58)($a1)
/* 9C714C 80241D6C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7150 80241D70 0C0B1EAF */  jal       get_variable
/* 9C7154 80241D74 0000202D */   daddu    $a0, $zero, $zero
/* 9C7158 80241D78 0040182D */  daddu     $v1, $v0, $zero
/* 9C715C 80241D7C 24020001 */  addiu     $v0, $zero, 1
/* 9C7160 80241D80 14620006 */  bne       $v1, $v0, .L80241D9C
/* 9C7164 80241D84 24020002 */   addiu    $v0, $zero, 2
/* 9C7168 80241D88 44800000 */  mtc1      $zero, $f0
/* 9C716C 80241D8C 00000000 */  nop       
/* 9C7170 80241D90 44050000 */  mfc1      $a1, $f0
/* 9C7174 80241D94 0809076D */  j         .L80241DB4
/* 9C7178 80241D98 0000202D */   daddu    $a0, $zero, $zero
.L80241D9C:
/* 9C717C 80241D9C 14620008 */  bne       $v1, $v0, .L80241DC0
/* 9C7180 80241DA0 24040001 */   addiu    $a0, $zero, 1
/* 9C7184 80241DA4 44800000 */  mtc1      $zero, $f0
/* 9C7188 80241DA8 00000000 */  nop       
/* 9C718C 80241DAC 44050000 */  mfc1      $a1, $f0
/* 9C7190 80241DB0 00000000 */  nop       
.L80241DB4:
/* 9C7194 80241DB4 00A0302D */  daddu     $a2, $a1, $zero
/* 9C7198 80241DB8 0C01C5A4 */  jal       func_80071690
/* 9C719C 80241DBC 00A0382D */   daddu    $a3, $a1, $zero
.L80241DC0:
/* 9C71A0 80241DC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C71A4 80241DC4 03E00008 */  jr        $ra
/* 9C71A8 80241DC8 27BD0018 */   addiu    $sp, $sp, 0x18
