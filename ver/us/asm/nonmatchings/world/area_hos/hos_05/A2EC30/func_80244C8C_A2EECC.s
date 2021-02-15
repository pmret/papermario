.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244C8C_A2EECC
/* A2EECC 80244C8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2EED0 80244C90 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2EED4 80244C94 0C090C40 */  jal       func_80243100_A2D340
/* A2EED8 80244C98 00000000 */   nop
/* A2EEDC 80244C9C 3C048025 */  lui       $a0, %hi(D_8024DBCC_A37E0C)
/* A2EEE0 80244CA0 0C09127C */  jal       func_802449F0_A2EC30
/* A2EEE4 80244CA4 2484DBCC */   addiu    $a0, $a0, %lo(D_8024DBCC_A37E0C)
/* A2EEE8 80244CA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2EEEC 80244CAC 03E00008 */  jr        $ra
/* A2EEF0 80244CB0 27BD0018 */   addiu    $sp, $sp, 0x18
/* A2EEF4 80244CB4 00000000 */  nop
/* A2EEF8 80244CB8 00000000 */  nop
/* A2EEFC 80244CBC 00000000 */  nop
