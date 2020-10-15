.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_spirits_cleanup
/* 140C18 8024D8D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 140C1C 8024D8DC AFB10014 */  sw        $s1, 0x14($sp)
/* 140C20 8024D8E0 0000882D */  daddu     $s1, $zero, $zero
/* 140C24 8024D8E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 140C28 8024D8E8 3C108027 */  lui       $s0, 0x8027
/* 140C2C 8024D8EC 261006C0 */  addiu     $s0, $s0, 0x6c0
/* 140C30 8024D8F0 AFBF0018 */  sw        $ra, 0x18($sp)
.L8024D8F4:
/* 140C34 8024D8F4 8E040000 */  lw        $a0, ($s0)
/* 140C38 8024D8F8 26100004 */  addiu     $s0, $s0, 4
/* 140C3C 8024D8FC 0C0B797A */  jal       func_802DE5E8
/* 140C40 8024D900 26310001 */   addiu    $s1, $s1, 1
/* 140C44 8024D904 2A220007 */  slti      $v0, $s1, 7
/* 140C48 8024D908 1440FFFA */  bnez      $v0, .L8024D8F4
/* 140C4C 8024D90C 00000000 */   nop      
/* 140C50 8024D910 8FBF0018 */  lw        $ra, 0x18($sp)
/* 140C54 8024D914 8FB10014 */  lw        $s1, 0x14($sp)
/* 140C58 8024D918 8FB00010 */  lw        $s0, 0x10($sp)
/* 140C5C 8024D91C 03E00008 */  jr        $ra
/* 140C60 8024D920 27BD0020 */   addiu    $sp, $sp, 0x20
/* 140C64 8024D924 00000000 */  nop       
/* 140C68 8024D928 00000000 */  nop       
/* 140C6C 8024D92C 00000000 */  nop       
