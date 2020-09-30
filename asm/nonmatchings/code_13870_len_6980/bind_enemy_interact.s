.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_enemy_interact
/* 19E1C 8003EA1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19E20 8003EA20 AFB00010 */  sw        $s0, 0x10($sp)
/* 19E24 8003EA24 0080802D */  daddu     $s0, $a0, $zero
/* 19E28 8003EA28 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19E2C 8003EA2C AFB10014 */  sw        $s1, 0x14($sp)
/* 19E30 8003EA30 8E020038 */  lw        $v0, 0x38($s0)
/* 19E34 8003EA34 10400004 */  beqz      $v0, .L8003EA48
/* 19E38 8003EA38 00A0882D */   daddu    $s1, $a1, $zero
/* 19E3C 8003EA3C 8C440144 */  lw        $a0, 0x144($v0)
/* 19E40 8003EA40 0C0B102B */  jal       kill_script_by_ID
/* 19E44 8003EA44 00000000 */   nop      
.L8003EA48:
/* 19E48 8003EA48 0220202D */  daddu     $a0, $s1, $zero
/* 19E4C 8003EA4C 2405000A */  addiu     $a1, $zero, 0xa
/* 19E50 8003EA50 0000302D */  daddu     $a2, $zero, $zero
/* 19E54 8003EA54 0C0B0CF8 */  jal       start_script
/* 19E58 8003EA58 AE040020 */   sw       $a0, 0x20($s0)
/* 19E5C 8003EA5C 0040182D */  daddu     $v1, $v0, $zero
/* 19E60 8003EA60 AE030038 */  sw        $v1, 0x38($s0)
/* 19E64 8003EA64 8C620144 */  lw        $v0, 0x144($v1)
/* 19E68 8003EA68 AE020050 */  sw        $v0, 0x50($s0)
/* 19E6C 8003EA6C AC700148 */  sw        $s0, 0x148($v1)
/* 19E70 8003EA70 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19E74 8003EA74 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E78 8003EA78 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E7C 8003EA7C 03E00008 */  jr        $ra
/* 19E80 8003EA80 27BD0020 */   addiu    $sp, $sp, 0x20
