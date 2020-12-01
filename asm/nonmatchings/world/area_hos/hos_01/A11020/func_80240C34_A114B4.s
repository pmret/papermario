.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C34_A114B4
/* A114B4 80240C34 3C06FC12 */  lui       $a2, 0xfc12
/* A114B8 80240C38 34C61624 */  ori       $a2, $a2, 0x1624
/* A114BC 80240C3C 3C05FF2F */  lui       $a1, 0xff2f
/* A114C0 80240C40 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* A114C4 80240C44 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* A114C8 80240C48 8C820000 */  lw        $v0, ($a0)
/* A114CC 80240C4C 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A114D0 80240C50 0040182D */  daddu     $v1, $v0, $zero
/* A114D4 80240C54 24420008 */  addiu     $v0, $v0, 8
/* A114D8 80240C58 AC820000 */  sw        $v0, ($a0)
/* A114DC 80240C5C AC660000 */  sw        $a2, ($v1)
/* A114E0 80240C60 AC650004 */  sw        $a1, 4($v1)
/* A114E4 80240C64 24430008 */  addiu     $v1, $v0, 8
/* A114E8 80240C68 AC830000 */  sw        $v1, ($a0)
/* A114EC 80240C6C 3C048024 */  lui       $a0, %hi(D_80241C33)
/* A114F0 80240C70 90841C33 */  lbu       $a0, %lo(D_80241C33)($a0)
/* A114F4 80240C74 3C03FA00 */  lui       $v1, 0xfa00
/* A114F8 80240C78 AC430000 */  sw        $v1, ($v0)
/* A114FC 80240C7C 03E00008 */  jr        $ra
/* A11500 80240C80 AC440004 */   sw       $a0, 4($v0)
