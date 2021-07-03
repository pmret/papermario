.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8024F550_852120
.ascii "hos_bg\0\0mac_05\0\0mac_02\0\0omo_03\0\0hos_20\0\0\0\0\0\0\0\0\0\0"

.section .text

glabel func_80240000_842BD0
/* 842BD0 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 842BD4 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 842BD8 80240008 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 842BDC 8024000C AFBF0010 */  sw        $ra, 0x10($sp)
/* 842BE0 80240010 8443008E */  lh        $v1, 0x8e($v0)
/* 842BE4 80240014 24020004 */  addiu     $v0, $zero, 4
/* 842BE8 80240018 14620006 */  bne       $v1, $v0, .L80240034
/* 842BEC 8024001C 00000000 */   nop
/* 842BF0 80240020 3C04800E */  lui       $a0, %hi(D_800D9668)
/* 842BF4 80240024 24849668 */  addiu     $a0, $a0, %lo(D_800D9668)
/* 842BF8 80240028 3C058025 */  lui       $a1, %hi(D_8024F550_852120)
/* 842BFC 8024002C 0C01953C */  jal       sprintf
/* 842C00 80240030 24A5F550 */   addiu    $a1, $a1, %lo(D_8024F550_852120)
.L80240034:
/* 842C04 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* 842C08 80240038 0000102D */  daddu     $v0, $zero, $zero
/* 842C0C 8024003C 03E00008 */  jr        $ra
/* 842C10 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* 842C14 80240044 00000000 */  nop
/* 842C18 80240048 00000000 */  nop
/* 842C1C 8024004C 00000000 */  nop
