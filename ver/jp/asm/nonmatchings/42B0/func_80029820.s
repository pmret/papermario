.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029820
/* 4C20 80029820 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 4C24 80029824 AFB20050 */  sw        $s2, 0x50($sp)
/* 4C28 80029828 0080902D */  daddu     $s2, $a0, $zero
/* 4C2C 8002982C AFB40058 */  sw        $s4, 0x58($sp)
/* 4C30 80029830 00A0A02D */  daddu     $s4, $a1, $zero
/* 4C34 80029834 AFB30054 */  sw        $s3, 0x54($sp)
/* 4C38 80029838 00C0982D */  daddu     $s3, $a2, $zero
/* 4C3C 8002983C 0260282D */  daddu     $a1, $s3, $zero
/* 4C40 80029840 AFBF005C */  sw        $ra, 0x5c($sp)
/* 4C44 80029844 AFB1004C */  sw        $s1, 0x4c($sp)
/* 4C48 80029848 0C018608 */  jal       func_80061820
/* 4C4C 8002984C AFB00048 */   sw       $s0, 0x48($sp)
/* 4C50 80029850 27B00028 */  addiu     $s0, $sp, 0x28
/* 4C54 80029854 0200202D */  daddu     $a0, $s0, $zero
/* 4C58 80029858 27B10040 */  addiu     $s1, $sp, 0x40
/* 4C5C 8002985C 0220282D */  daddu     $a1, $s1, $zero
/* 4C60 80029860 0C019554 */  jal       func_80065550
/* 4C64 80029864 24060001 */   addiu    $a2, $zero, 1
/* 4C68 80029868 27A50010 */  addiu     $a1, $sp, 0x10
/* 4C6C 8002986C 3C04800A */  lui       $a0, %hi(nuPiCartHandle)
/* 4C70 80029870 8C84A618 */  lw        $a0, %lo(nuPiCartHandle)($a0)
/* 4C74 80029874 24060001 */  addiu     $a2, $zero, 1
/* 4C78 80029878 A3A00012 */  sb        $zero, 0x12($sp)
/* 4C7C 8002987C AFB00014 */  sw        $s0, 0x14($sp)
/* 4C80 80029880 AFB20018 */  sw        $s2, 0x18($sp)
/* 4C84 80029884 AFB4001C */  sw        $s4, 0x1c($sp)
/* 4C88 80029888 0C01837C */  jal       func_80060DF0
/* 4C8C 8002988C AFB30020 */   sw       $s3, 0x20($sp)
/* 4C90 80029890 0200202D */  daddu     $a0, $s0, $zero
/* 4C94 80029894 0220282D */  daddu     $a1, $s1, $zero
/* 4C98 80029898 0C0195B0 */  jal       func_800656C0
/* 4C9C 8002989C 24060001 */   addiu    $a2, $zero, 1
/* 4CA0 800298A0 8FBF005C */  lw        $ra, 0x5c($sp)
/* 4CA4 800298A4 8FB40058 */  lw        $s4, 0x58($sp)
/* 4CA8 800298A8 8FB30054 */  lw        $s3, 0x54($sp)
/* 4CAC 800298AC 8FB20050 */  lw        $s2, 0x50($sp)
/* 4CB0 800298B0 8FB1004C */  lw        $s1, 0x4c($sp)
/* 4CB4 800298B4 8FB00048 */  lw        $s0, 0x48($sp)
/* 4CB8 800298B8 03E00008 */  jr        $ra
/* 4CBC 800298BC 27BD0060 */   addiu    $sp, $sp, 0x60
