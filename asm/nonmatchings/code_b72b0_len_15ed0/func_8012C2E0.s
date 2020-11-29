.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012C2E0
/* C29E0 8012C2E0 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* C29E4 8012C2E4 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* C29E8 8012C2E8 8C820000 */  lw        $v0, ($a0)
/* C29EC 8012C2EC 3C03E700 */  lui       $v1, 0xe700
/* C29F0 8012C2F0 0040282D */  daddu     $a1, $v0, $zero
/* C29F4 8012C2F4 24420008 */  addiu     $v0, $v0, 8
/* C29F8 8012C2F8 AC820000 */  sw        $v0, ($a0)
/* C29FC 8012C2FC ACA30000 */  sw        $v1, ($a1)
/* C2A00 8012C300 24430008 */  addiu     $v1, $v0, 8
/* C2A04 8012C304 ACA00004 */  sw        $zero, 4($a1)
/* C2A08 8012C308 AC830000 */  sw        $v1, ($a0)
/* C2A0C 8012C30C 3C03DE00 */  lui       $v1, %hi(D_DDFFC500)
/* C2A10 8012C310 AC430000 */  sw        $v1, ($v0)
/* C2A14 8012C314 3C038015 */  lui       $v1, %hi(D_8014C500)
/* C2A18 8012C318 2463C500 */  addiu     $v1, $v1, %lo(D_DDFFC500)
/* C2A1C 8012C31C 03E00008 */  jr        $ra
/* C2A20 8012C320 AC430004 */   sw       $v1, 4($v0)
