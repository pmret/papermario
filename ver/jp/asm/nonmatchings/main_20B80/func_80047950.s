.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047950
/* 22D50 80047950 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 22D54 80047954 00041040 */  sll       $v0, $a0, 1
/* 22D58 80047958 00441021 */  addu      $v0, $v0, $a0
/* 22D5C 8004795C 00021080 */  sll       $v0, $v0, 2
/* 22D60 80047960 00441023 */  subu      $v0, $v0, $a0
/* 22D64 80047964 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22D68 80047968 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22D6C 8004796C 00021100 */  sll       $v0, $v0, 4
/* 22D70 80047970 AFBF0010 */  sw        $ra, 0x10($sp)
/* 22D74 80047974 00621821 */  addu      $v1, $v1, $v0
/* 22D78 80047978 80620078 */  lb        $v0, 0x78($v1)
/* 22D7C 8004797C 10400008 */  beqz      $v0, .L800479A0
/* 22D80 80047980 24020001 */   addiu    $v0, $zero, 1
/* 22D84 80047984 8C64007C */  lw        $a0, 0x7c($v1)
/* 22D88 80047988 3C058010 */  lui       $a1, %hi(D_8010730C)
/* 22D8C 8004798C 24A5730C */  addiu     $a1, $a1, %lo(D_8010730C)
/* 22D90 80047990 A0600078 */  sb        $zero, 0x78($v1)
/* 22D94 80047994 A0620079 */  sb        $v0, 0x79($v1)
/* 22D98 80047998 0C05262B */  jal       func_801498AC
/* 22D9C 8004799C AC640080 */   sw       $a0, 0x80($v1)
.L800479A0:
/* 22DA0 800479A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 22DA4 800479A4 03E00008 */  jr        $ra
/* 22DA8 800479A8 27BD0018 */   addiu    $sp, $sp, 0x18
