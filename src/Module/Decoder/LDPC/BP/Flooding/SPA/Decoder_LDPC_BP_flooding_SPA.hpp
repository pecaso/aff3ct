#ifndef DECODER_LDPC_BP_FLOODING_SPA_HPP_
#define DECODER_LDPC_BP_FLOODING_SPA_HPP_

#include "Tools/Code/LDPC/Update_rule/SPA/Update_rule_SPA.hpp"

#include "../Decoder_LDPC_BP_flooding.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float>
class Decoder_LDPC_BP_flooding_SPA : public Decoder_LDPC_BP_flooding<B,R,tools::Update_rule_SPA<R>>
{
protected:
	std::vector<R> values;

public:
	Decoder_LDPC_BP_flooding_SPA(const int K, const int N, const int n_ite,
	                             const tools::Sparse_matrix &H,
	                             const std::vector<uint32_t> &info_bits_pos,
	                             const bool enable_syndrome = true,
	                             const int syndrome_depth = 1,
	                             const int n_frames = 1);
	virtual ~Decoder_LDPC_BP_flooding_SPA() = default;

protected:
	void _decode_single_ite(const std::vector<R> &msg_var_to_chk, std::vector<R> &msg_chk_to_var);
};
}
}

#include "Decoder_LDPC_BP_flooding_SPA.hxx"

#endif /* DECODER_LDPC_BP_FLOODING_SPA_HPP_ */