.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047C94
/* 23094 80047C94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 23098 80047C98 00041040 */  sll       $v0, $a0, 1
/* 2309C 80047C9C 00441021 */  addu      $v0, $v0, $a0
/* 230A0 80047CA0 00021080 */  sll       $v0, $v0, 2
/* 230A4 80047CA4 00441023 */  subu      $v0, $v0, $a0
/* 230A8 80047CA8 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 230AC 80047CAC 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 230B0 80047CB0 00021100 */  sll       $v0, $v0, 4
/* 230B4 80047CB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 230B8 80047CB8 00621821 */  addu      $v1, $v1, $v0
/* 230BC 80047CBC 80620098 */  lb        $v0, 0x98($v1)
/* 230C0 80047CC0 10400004 */  beqz      $v0, .L80047CD4
/* 230C4 80047CC4 00000000 */   nop
/* 230C8 80047CC8 8C64009C */  lw        $a0, 0x9c($v1)
/* 230CC 80047CCC 0C052669 */  jal       func_801499A4
/* 230D0 80047CD0 A0600098 */   sb       $zero, 0x98($v1)
.L80047CD4:
/* 230D4 80047CD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 230D8 80047CD8 03E00008 */  jr        $ra
/* 230DC 80047CDC 27BD0018 */   addiu    $sp, $sp, 0x18
