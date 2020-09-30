.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029860
/* 4C60 80029860 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 4C64 80029864 AFB20050 */  sw        $s2, 0x50($sp)
/* 4C68 80029868 0080902D */  daddu     $s2, $a0, $zero
/* 4C6C 8002986C AFB40058 */  sw        $s4, 0x58($sp)
/* 4C70 80029870 00A0A02D */  daddu     $s4, $a1, $zero
/* 4C74 80029874 AFB30054 */  sw        $s3, 0x54($sp)
/* 4C78 80029878 00C0982D */  daddu     $s3, $a2, $zero
/* 4C7C 8002987C 0260282D */  daddu     $a1, $s3, $zero
/* 4C80 80029880 AFBF005C */  sw        $ra, 0x5c($sp)
/* 4C84 80029884 AFB1004C */  sw        $s1, 0x4c($sp)
/* 4C88 80029888 0C018614 */  jal       osWritebackDCache
/* 4C8C 8002988C AFB00048 */   sw       $s0, 0x48($sp)
/* 4C90 80029890 27B00028 */  addiu     $s0, $sp, 0x28
/* 4C94 80029894 0200202D */  daddu     $a0, $s0, $zero
/* 4C98 80029898 27B10040 */  addiu     $s1, $sp, 0x40
/* 4C9C 8002989C 0220282D */  daddu     $a1, $s1, $zero
/* 4CA0 800298A0 0C019560 */  jal       osCreateMesgQueue
/* 4CA4 800298A4 24060001 */   addiu    $a2, $zero, 1
/* 4CA8 800298A8 27A50010 */  addiu     $a1, $sp, 0x10
/* 4CAC 800298AC 3C04800A */  lui       $a0, 0x800a
/* 4CB0 800298B0 8C84A638 */  lw        $a0, -0x59c8($a0)
/* 4CB4 800298B4 24060001 */  addiu     $a2, $zero, 1
/* 4CB8 800298B8 A3A00012 */  sb        $zero, 0x12($sp)
/* 4CBC 800298BC AFB00014 */  sw        $s0, 0x14($sp)
/* 4CC0 800298C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 4CC4 800298C4 AFB4001C */  sw        $s4, 0x1c($sp)
/* 4CC8 800298C8 0C018388 */  jal       osEPiStartDma
/* 4CCC 800298CC AFB30020 */   sw       $s3, 0x20($sp)
/* 4CD0 800298D0 0200202D */  daddu     $a0, $s0, $zero
/* 4CD4 800298D4 0220282D */  daddu     $a1, $s1, $zero
/* 4CD8 800298D8 0C0195BC */  jal       osRecvMesg
/* 4CDC 800298DC 24060001 */   addiu    $a2, $zero, 1
/* 4CE0 800298E0 8FBF005C */  lw        $ra, 0x5c($sp)
/* 4CE4 800298E4 8FB40058 */  lw        $s4, 0x58($sp)
/* 4CE8 800298E8 8FB30054 */  lw        $s3, 0x54($sp)
/* 4CEC 800298EC 8FB20050 */  lw        $s2, 0x50($sp)
/* 4CF0 800298F0 8FB1004C */  lw        $s1, 0x4c($sp)
/* 4CF4 800298F4 8FB00048 */  lw        $s0, 0x48($sp)
/* 4CF8 800298F8 03E00008 */  jr        $ra
/* 4CFC 800298FC 27BD0060 */   addiu    $sp, $sp, 0x60
