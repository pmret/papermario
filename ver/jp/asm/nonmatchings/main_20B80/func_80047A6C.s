.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047A6C
/* 22E6C 80047A6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 22E70 80047A70 00041040 */  sll       $v0, $a0, 1
/* 22E74 80047A74 00441021 */  addu      $v0, $v0, $a0
/* 22E78 80047A78 00021080 */  sll       $v0, $v0, 2
/* 22E7C 80047A7C 00441023 */  subu      $v0, $v0, $a0
/* 22E80 80047A80 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22E84 80047A84 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22E88 80047A88 00021100 */  sll       $v0, $v0, 4
/* 22E8C 80047A8C AFBF0010 */  sw        $ra, 0x10($sp)
/* 22E90 80047A90 00621821 */  addu      $v1, $v1, $v0
/* 22E94 80047A94 80620084 */  lb        $v0, 0x84($v1)
/* 22E98 80047A98 10400008 */  beqz      $v0, .L80047ABC
/* 22E9C 80047A9C 00000000 */   nop
/* 22EA0 80047AA0 8C640088 */  lw        $a0, 0x88($v1)
/* 22EA4 80047AA4 3C058010 */  lui       $a1, %hi(D_80107604)
/* 22EA8 80047AA8 24A57604 */  addiu     $a1, $a1, %lo(D_80107604)
/* 22EAC 80047AAC A0600084 */  sb        $zero, 0x84($v1)
/* 22EB0 80047AB0 A0600085 */  sb        $zero, 0x85($v1)
/* 22EB4 80047AB4 0C05262B */  jal       func_801498AC
/* 22EB8 80047AB8 AC64008C */   sw       $a0, 0x8c($v1)
.L80047ABC:
/* 22EBC 80047ABC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 22EC0 80047AC0 03E00008 */  jr        $ra
/* 22EC4 80047AC4 27BD0018 */   addiu    $sp, $sp, 0x18
