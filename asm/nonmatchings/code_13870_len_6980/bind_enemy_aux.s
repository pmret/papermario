.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_enemy_aux
/* 19DB4 8003E9B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19DB8 8003E9B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 19DBC 8003E9BC 0080802D */  daddu     $s0, $a0, $zero
/* 19DC0 8003E9C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19DC4 8003E9C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 19DC8 8003E9C8 8E020044 */  lw        $v0, 0x44($s0)
/* 19DCC 8003E9CC 10400004 */  beqz      $v0, .L8003E9E0
/* 19DD0 8003E9D0 00A0882D */   daddu    $s1, $a1, $zero
/* 19DD4 8003E9D4 8C440144 */  lw        $a0, 0x144($v0)
/* 19DD8 8003E9D8 0C0B102B */  jal       kill_script_by_ID
/* 19DDC 8003E9DC 00000000 */   nop      
.L8003E9E0:
/* 19DE0 8003E9E0 0220202D */  daddu     $a0, $s1, $zero
/* 19DE4 8003E9E4 2405000A */  addiu     $a1, $zero, 0xa
/* 19DE8 8003E9E8 0000302D */  daddu     $a2, $zero, $zero
/* 19DEC 8003E9EC 0C0B0CF8 */  jal       start_script
/* 19DF0 8003E9F0 AE04002C */   sw       $a0, 0x2c($s0)
/* 19DF4 8003E9F4 0040182D */  daddu     $v1, $v0, $zero
/* 19DF8 8003E9F8 AE030044 */  sw        $v1, 0x44($s0)
/* 19DFC 8003E9FC 8C620144 */  lw        $v0, 0x144($v1)
/* 19E00 8003EA00 AE02005C */  sw        $v0, 0x5c($s0)
/* 19E04 8003EA04 AC700148 */  sw        $s0, 0x148($v1)
/* 19E08 8003EA08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19E0C 8003EA0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E10 8003EA10 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E14 8003EA14 03E00008 */  jr        $ra
/* 19E18 8003EA18 27BD0020 */   addiu    $sp, $sp, 0x20
