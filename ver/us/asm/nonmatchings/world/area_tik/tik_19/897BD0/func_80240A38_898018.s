.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_19_UnkFunc19
/* 898018 80240A38 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* 89801C 80240A3C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* 898020 80240A40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 898024 80240A44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 898028 80240A48 00021100 */  sll       $v0, $v0, 4
/* 89802C 80240A4C 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* 898030 80240A50 00822021 */  addu      $a0, $a0, $v0
/* 898034 80240A54 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* 898038 80240A58 0C0496CF */  jal       set_message_string
/* 89803C 80240A5C 0000282D */   daddu    $a1, $zero, $zero
/* 898040 80240A60 8FBF0010 */  lw        $ra, 0x10($sp)
/* 898044 80240A64 24020002 */  addiu     $v0, $zero, 2
/* 898048 80240A68 03E00008 */  jr        $ra
/* 89804C 80240A6C 27BD0018 */   addiu    $sp, $sp, 0x18
