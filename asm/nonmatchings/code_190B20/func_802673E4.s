.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802673E4
/* 195CC4 802673E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 195CC8 802673E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 195CCC 802673EC 00A0802D */  daddu     $s0, $a1, $zero
/* 195CD0 802673F0 2403FFFB */  addiu     $v1, $zero, -5
/* 195CD4 802673F4 0000202D */  daddu     $a0, $zero, $zero
/* 195CD8 802673F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 195CDC 802673FC 8E020000 */  lw        $v0, ($s0)
/* 195CE0 80267400 8E050058 */  lw        $a1, 0x58($s0)
/* 195CE4 80267404 8E06005C */  lw        $a2, 0x5c($s0)
/* 195CE8 80267408 8E070060 */  lw        $a3, 0x60($s0)
/* 195CEC 8026740C 00431024 */  and       $v0, $v0, $v1
/* 195CF0 80267410 0C044898 */  jal       create_shadow_type
/* 195CF4 80267414 AE020000 */   sw       $v0, ($s0)
/* 195CF8 80267418 AE02009C */  sw        $v0, 0x9c($s0)
/* 195CFC 8026741C 92020072 */  lbu       $v0, 0x72($s0)
/* 195D00 80267420 3C014038 */  lui       $at, 0x4038
/* 195D04 80267424 44811800 */  mtc1      $at, $f3
/* 195D08 80267428 44801000 */  mtc1      $zero, $f2
/* 195D0C 8026742C 44820000 */  mtc1      $v0, $f0
/* 195D10 80267430 00000000 */  nop       
/* 195D14 80267434 46800021 */  cvt.d.w   $f0, $f0
/* 195D18 80267438 46220003 */  div.d     $f0, $f0, $f2
/* 195D1C 8026743C 46200020 */  cvt.s.d   $f0, $f0
/* 195D20 80267440 E60000A0 */  swc1      $f0, 0xa0($s0)
/* 195D24 80267444 8FBF0014 */  lw        $ra, 0x14($sp)
/* 195D28 80267448 8FB00010 */  lw        $s0, 0x10($sp)
/* 195D2C 8026744C 03E00008 */  jr        $ra
/* 195D30 80267450 27BD0018 */   addiu    $sp, $sp, 0x18
