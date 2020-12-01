.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel LoadActionCommand
/* 196AA0 802681C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 196AA4 802681C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 196AA8 802681C8 8C82000C */  lw        $v0, 0xc($a0)
/* 196AAC 802681CC 0C0B1EAF */  jal       get_variable
/* 196AB0 802681D0 8C450000 */   lw       $a1, ($v0)
/* 196AB4 802681D4 3C068029 */  lui       $a2, %hi(D_802944C0)
/* 196AB8 802681D8 24C644C0 */  addiu     $a2, $a2, %lo(D_802944C0)
/* 196ABC 802681DC 00021840 */  sll       $v1, $v0, 1
/* 196AC0 802681E0 00621821 */  addu      $v1, $v1, $v0
/* 196AC4 802681E4 00031080 */  sll       $v0, $v1, 2
/* 196AC8 802681E8 00461021 */  addu      $v0, $v0, $a2
/* 196ACC 802681EC 8C440000 */  lw        $a0, ($v0)
/* 196AD0 802681F0 24620001 */  addiu     $v0, $v1, 1
/* 196AD4 802681F4 00021080 */  sll       $v0, $v0, 2
/* 196AD8 802681F8 00461021 */  addu      $v0, $v0, $a2
/* 196ADC 802681FC 24630002 */  addiu     $v1, $v1, 2
/* 196AE0 80268200 00031880 */  sll       $v1, $v1, 2
/* 196AE4 80268204 00661821 */  addu      $v1, $v1, $a2
/* 196AE8 80268208 8C450000 */  lw        $a1, ($v0)
/* 196AEC 8026820C 0C00A5CF */  jal       dma_copy
/* 196AF0 80268210 8C660000 */   lw       $a2, ($v1)
/* 196AF4 80268214 8FBF0010 */  lw        $ra, 0x10($sp)
/* 196AF8 80268218 24020002 */  addiu     $v0, $zero, 2
/* 196AFC 8026821C 03E00008 */  jr        $ra
/* 196B00 80268220 27BD0018 */   addiu    $sp, $sp, 0x18
