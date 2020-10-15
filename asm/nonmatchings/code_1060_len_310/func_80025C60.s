.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025C60
/* 1060 80025C60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1064 80025C64 3C05B3FF */  lui       $a1, 0xb3ff
/* 1068 80025C68 34A50014 */  ori       $a1, $a1, 0x14
/* 106C 80025C6C AFB00010 */  sw        $s0, 0x10($sp)
/* 1070 80025C70 3C10800A */  lui       $s0, %hi(carthandle)
/* 1074 80025C74 2610A638 */  addiu     $s0, $s0, %lo(carthandle)
/* 1078 80025C78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 107C 80025C7C 8E040000 */  lw        $a0, ($s0)
/* 1080 80025C80 0C018358 */  jal       osEPiWriteIo
/* 1084 80025C84 0000302D */   daddu    $a2, $zero, $zero
/* 1088 80025C88 3C05B3FF */  lui       $a1, 0xb3ff
/* 108C 80025C8C 34A50004 */  ori       $a1, $a1, 4
/* 1090 80025C90 8E040000 */  lw        $a0, ($s0)
/* 1094 80025C94 0C018358 */  jal       osEPiWriteIo
/* 1098 80025C98 0000302D */   daddu    $a2, $zero, $zero
/* 109C 80025C9C 3C05B3FF */  lui       $a1, 0xb3ff
/* 10A0 80025CA0 3C064953 */  lui       $a2, 0x4953
/* 10A4 80025CA4 8E040000 */  lw        $a0, ($s0)
/* 10A8 80025CA8 0C018358 */  jal       osEPiWriteIo
/* 10AC 80025CAC 34C63634 */   ori      $a2, $a2, 0x3634
/* 10B0 80025CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10B4 80025CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 10B8 80025CB8 03E00008 */  jr        $ra
/* 10BC 80025CBC 27BD0018 */   addiu    $sp, $sp, 0x18
