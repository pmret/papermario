.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024085C
/* 83205C 8024085C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832060 80240860 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832064 80240864 0C00EABB */  jal       get_npc_unsafe
/* 832068 80240868 8C84014C */   lw       $a0, 0x14c($a0)
/* 83206C 8024086C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832070 80240870 0000102D */  daddu     $v0, $zero, $zero
/* 832074 80240874 03E00008 */  jr        $ra
/* 832078 80240878 27BD0018 */   addiu    $sp, $sp, 0x18
